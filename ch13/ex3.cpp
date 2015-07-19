#include <iostream>

using std::cout;
using std::endl;

/*

Write intrusive and non-intrusive doubly-linked lists. What operations should be
provided in addition to the ones you found necessary to supply for a singly-
linked list?

*/

template<class T> class Link {
	T* pre;
	T* suc;
public:
	Link(T* pre, T* suc) : pre(pre), suc(suc) {}
	const T* Pre() const { return pre; }
	const T* Suc() const { return suc; }
	T* Pre() { return pre; }
	T* Suc() { return suc; }
};

template<class T> class Intrusive : public Link< Intrusive<T> > {
	T val;
public:
	Intrusive(Intrusive *pre, Intrusive *suc, const T& val) : Link< Intrusive<T> >(pre, suc),
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
		Intrusive<T>* new_head = new Intrusive<T>(0, head, val);
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

