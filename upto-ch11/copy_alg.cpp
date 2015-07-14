#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){

	string pals[] = { "jerry", "elaine", "george", "kramer" };

	vector<string> vpals;
	copy(pals, pals + sizeof(pals) / sizeof(pals[0]), back_inserter(vpals));

	for (auto ipals = vpals.begin(); ipals != vpals.end(); ++ipals)
		cout << *ipals << endl;

	return 0;
}
