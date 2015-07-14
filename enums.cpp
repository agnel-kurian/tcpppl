#include <iostream>

using namespace std;

enum Clan {
	Sith, Jedi, Gungan, Wookie
};

Clan& operator++(Clan& c){
	c = (Clan)(((int)c) + 1);
	return c;
}

Clan& operator++(Clan& c, int){
	c = (Clan)(((int)c) + 1);
	return c;
}

int main(){
	Clan c1 = Sith;
	c1++;
	cout << c1 << endl;
	return 0;
}
