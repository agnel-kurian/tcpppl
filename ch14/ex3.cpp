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

	Node(const string& s, Node *l = 0, Node *r = 0)
		: s(s), n(1), l(l), r(r) {}

	void print_all(int indent = 0){
		string ind(indent, ' ');
		cout << ind << s << ": " << n << endl;
		if(l) l->print_all(++indent);
		if(r) r->print_all(indent);
		--indent;
	}

	~Node(){
		if(l) delete l;
		if(r) delete r;
	}

	Node* find(const char* c_str);
	Node* find(const string& s);

	int count() const throw() { return n; }
  const string& str(){ return s; }
};

class Not_found {
};

Node *Node::find(const char* c_str){
	string s(c_str);
	return find(s);
}

Node *Node::find(const string& s){
		Node *p = this;
		while(p){
			if(s < p->s) p = p->l;
			else if(s > p->s) p = p->r;
			else return p;
		}

		throw Not_found();
}

int main(){
	string s;
	Node *head = 0;
	while(cin >> s){
		if(head == 0)
			head = new Node(s);
		else
			head->append(s);
	}

	if(head) {
		Node *the_node = head->find("the");
		cout << the_node->str() << ": " << the_node->count() << endl;
		head->print_all();
		delete head;
	}

	return 0;
}

