#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Node {
	string s;
	Node *l;
	Node *r;
	int n;

public:
	Node& append(const string& s){
		if(s < this->s){
			if(l)	return l->append(s);
			l = new Node(s);
			return *l;
		}
		else if(s > this->s){
			if(r) return r->append(s);
			r = new Node(s);
			return *r;
		}
		else {
			++n;
			return * this;
		}
	}

	Node(const string& s, Node *l = 0, Node *r = 0) : s(s), n(1), l(l), r(r) {}
	void print_all(){
		cout << s << ": " << n << endl;
		if(l) l->print_all();
		if(r) r->print_all();
	}

	~Node(){
		if(l) delete l;
		if(r) delete r;
	}
};

int main(){
	string s;
	Node *head = 0;
	while(cin >> s){
		if(head == 0)
			head = new Node(s);
		else
			head->append(s);
	}

	if(head) { head->print_all(); delete head; }
	return 0;
}

