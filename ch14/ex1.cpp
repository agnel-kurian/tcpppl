#include <iostream>

using std::cout;
using std::endl;

template<class H, class F> class STC {
	H old;
	F setter;
public:
	STC(H f, F setter) : setter(setter) {
		cout << "setting" << endl;
		old = setter(f);
	}

	~STC() {
		cout << "restoring" << endl;
		setter(old);
	}
};

class Yerr {
};

class Yunexpected : Yerr {
};

void throwY() throw(Yunexpected) { throw Yunexpected(); }
int my_errno = 42;
using std::unexpected_handler;

void throw_int() throw(int) { throw int(); }
void default_throw_int() throw(int) { throw 0; }
void (*int_thrower)() = default_throw_int;
void(*set_throw_int(void (*f)()))(){
	cout << "setting throw int" << endl;
	void (*g)() = int_thrower;
	int_thrower = f;
	return g;
}
int main(){
	typedef unexpected_handler (*Setter)(unexpected_handler);

	STC<unexpected_handler, Setter> unexpectedY(&throwY, std::set_unexpected);
	STC<void (*)(), void (*(*)( void(*)() ))() > unexpected_int(&throw_int, set_throw_int);
	//set_throw_int(throw_int);
	return 0;
}

