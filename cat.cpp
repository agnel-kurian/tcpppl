#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){

	for (int i = 1; i < argc; ++i){
		ifstream fin(argv[i]);
		char c;
		while (fin){
			fin.get(c);
			cout << int(c) << "," << c << endl;
		}
	}

	return 0;
}