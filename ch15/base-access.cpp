#include <iostream>

using std::cout;
using std::endl;

class B {
	void pri_f(){}
protected:
	void pro_f(){}
public:
	void pub_f(){}
};

class PubD : public B {
	void f(){
		//pri_f();
		pro_f();
		pub_f();
	}
};

class ProD : protected B {
	void f(){
		//pri_f();
		pro_f();
		pub_f();
		B* bp = this;
	}
};

class PriD : private B {
	void f(){
		//pri_f();
		pro_f();
		pub_f();
		B* bp = this;
	}
};

int main(){
	B* bp;

	PubD pub_d;
	bp = &pub_d;

	ProD pro_d;
	bp = &pro_d;

	PriD pri_d;
	bp = &pri_d;
	
	return 0;
}

