// exp1.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

class Node {
	int index;
public:
	Node(int index) : index(index) {}
	int& Index(){
		cout << "int& Node::Index();" << endl;
		return index;
	}

	const int& Index() const {
		cout << "const int& Node::Index() const;" << endl;
		return index;
	}

	int& operator[](int i){
		cout << "int& operator[](int i)" << endl;
		return index;
	}

	const int& operator[](int i) const {
		cout << "const int& operator[](int i) const" << endl;
		return index;
	}
};

int main(int argc, char* argv[])
{
	Node n(1);
	cout << n.Index() << endl;
	n.Index() = 10;
	
	int a1 = n[10];
	n[10] = 100;
	const int a2 = n[10];
	const int& a3 = n[10];
	int& a4 = n[10];

	const Node n2(2);
	const int& a = n2[10];
	const int& b = n2.Index();
	return 0;
}

