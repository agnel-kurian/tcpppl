#include <iostream>

int main(){
	char carr[] = "brownie";
	const char *p1 = carr;
	char const * p2 = carr;

	p2 = &carr[1];
	p1 = &carr[1];

	return 0;
}