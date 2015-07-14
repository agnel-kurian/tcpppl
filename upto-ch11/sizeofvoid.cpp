#include <iostream>

using namespace std;


int main(){
	int x = 42;
	void *p = &x;
	void *q = p + 1;
	cout << p << ", " << q << endl;
	return 0;
}
