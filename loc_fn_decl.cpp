#include <iostream>

int advance(int i, int step = 1);

int main(){

	//int advance(int i, int step = 3);
	std::cout << advance(5) << std::endl;
	//std::cout << advance(5, 2) << std::endl;

	return 0;
}

int advance(int i, int step){
	return i + step;
}