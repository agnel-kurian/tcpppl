#include <iostream>
#include <limits>
#include <string>

using namespace std;

template<typename T> void min_max(const string &s){
	cout << s << ": " << numeric_limits<T>::min() << ", "
		<< numeric_limits<T>::max() << endl;
}

int main(){
	min_max<char>("char");
	min_max<short>("short");
	min_max<int>("int");
	min_max<long>("long");
	min_max<float>("float");
	min_max<double>("double");
	min_max<long double>("long double");
	min_max<unsigned>("unsigned");
	return 0;
}
