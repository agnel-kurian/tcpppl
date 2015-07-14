#include <iostream>
using namespace std;

void ex1(){
	char *p = 0;
	int i[10] = {0, 1, 2, 3, 4, 5, 6, 8, 9};
	int (&ir)[10] = i;
	char *pa[] = { "a", "b", "c"};
	char **pp = &p;
	const int a = 50;
	const int *ptr_a = &a;
	int b = 10;
	int * const ptr_b = &b;
	
}

int main(){
	return 0;
}
