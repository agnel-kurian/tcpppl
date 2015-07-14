#include <iostream>

class ImperialLength {
	int inches;
public:
	ImperialLength(int inches) : inches(inches) {}
//	operator int(){ return inches; }
};

using std::cout;
using std::endl;

int main(){
	ImperialLength il1 = 10;
	cout << il1 << endl;
	return 0;
}
