#include <iostream>

using std::cout;
using std::endl;

/*

Write a singly-linked list class template that accepts elements of any type
derived from a class Link that holds the information necessary to link elements.
This is called an intrusive list. Using this list, write a singly-linked list
that accepts elements of any type (a non-intrusive list). Compare the
performance of the two list classes and discuss the tradeoffs between them.

*/

template<class T> class Link {
	T* suc;
public:
	Link(T* suc) : suc(suc) {}
	const T* Suc() const { return suc; }
	T* Suc() { return suc; }
};

template<class T> class Intrusive : public Link< Intrusive<T> > {
	T val;
public:
	Intrusive(Intrusive *suc, const T& val) : Link< Intrusive<T> >(suc),
		val(val) {
	}
	const T& Val() const { return val; }
	T& Val() { return val; }
};

template<class T> class NonIntrusive {
	Intrusive<T>* head;
public:
	NonIntrusive() : head(0) {}
	void push_front(const T& val){
		Intrusive<T>* new_head = new Intrusive<T>(head, val);
		head = new_head;
	}

	void print_all(){
		for(const Intrusive<T>* p = head; p; p = p->Suc())
			cout << p->Val() << endl;
	}

	void zero(){
		for(Intrusive<T>* p = head; p; p = p->Suc())
			p->Val() = 0;
	}
};

int main(){
	NonIntrusive<int> ints;
	ints.push_front(2);
	ints.push_front(3);
	ints.push_front(5);
	ints.push_front(7);

	ints.print_all();
	ints.zero();
	ints.print_all();

	return 0;
}

