#include <iostream>

using namespace std; 

typedef void(*fp_t)(char*, int&);

fp_t f1(fp_t a){
	return a;
}

int main(){
	void f(char*, int&);
	void(*fp)(char*, int&) = 0;

	return 0;
}