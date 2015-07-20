#include <iostream>

using std::cout;
using std::endl;

/*
Complete the Ptr_to_T class from 11.11 as a template that uses exceptions to
signal run-time errors
*/ 

class Out_of_range {
};

template<class T> class Ptr_to_T {
	T* p;
	T* array;
	int size;

	bool is_valid(T* p){
		return !(p < array || p >= array + size);
	}

public:
	//	bind to array v of size s, initial value p
	Ptr_to_T(T* p, T* v, int s) : p(p), array(v), size(s) {}

	//	bind to single object, initial value p
	Ptr_to_T(T* p) : p(p), array(p), size(1) {}	

	Ptr_to_T& operator++(){			//	prefix
		++p;
		return *this;
	}

	Ptr_to_T operator++(int){	// postfix
		Ptr_to_T tmp = *this;
		p++;
		return tmp;
	}
	
	Ptr_to_T& operator--(){			//	prefix
		--p;
		return *this;
	}

	Ptr_to_T operator--(int){	//	postfix
		Ptr_to_T<T> tmp = *this;
		p--;
		return tmp;
	}

	T& operator*(){							//	prefix
		if(!is_valid(p))
			throw Out_of_range();
		return *p;
	}
};

int main(){
	int v[200];
	Ptr_to_T<int> p(&v[0], v, 200);
	p--;

	try {
		*p = 42;
	}
	catch(Out_of_range){
		cout << "pointer was out of range" << endl;
	}

	++p;
	*p = 42;
	cout << *p << endl;

	return 0;
}

