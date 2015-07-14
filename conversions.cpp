#include <iostream>

using std::cout;
using std::endl;

struct X {
	int i;
	X(int){ cout << "in X::(int)" << endl; }
	X operator+(int){ cout << "in X::operator+(int)" << endl; }
};

struct Y {
	int i;
	Y(X){ cout << "in Y::Y(X)" << endl; }
	Y operator+(X){ cout << "in Y::operator+(X)" << endl; return Y(X(10)); }
	operator int(){ cout << "in Y::operator int()" << endl; return 0; }
};

X operator*(X, Y){ cout << "int operator*(X,Y)" << endl; }
int f(X){ cout << "in f(X)" << endl; return 0; }

X x = 1;
Y y = x;
int i = 2;

int main(){
 cout << "----------" << endl;
	i + 10; cout << "----------" << endl;
  int(y) + 10; cout << "----------" << endl;
	y + X(10 * int(y)); cout << "----------" << endl;
	x + y + i; cout << "----------" << endl;
	x * x + i; cout << "----------" << endl;
	f(7); cout << "----------" << endl;
	f(int(y)); cout << "----------" << endl;
	y + y; cout << "----------" << endl;
	106 + y; cout << "----------" << endl;

	return 0;
}


