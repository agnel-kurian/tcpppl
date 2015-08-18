#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
  multimap<string,string> db;
  string k, v;
  cin >> k;
  while(k != "."){
    cin >> v;
    db.insert(make_pair(k, v));
    cin >> k;
  }
  
  for(multimap<string,string>::iterator i = db.begin();
		i != db.end(); ++i)
    cout << i->first << ": " << i->second << endl;
  

	string kfind;
	cin >> kfind;

	typedef multimap<string,string>::iterator I;
	pair<I,I> p = db.equal_range(kfind);

	for(I it = p.first; it != p.second; ++it)
		cout << it->second << endl;

  return 0;
}
