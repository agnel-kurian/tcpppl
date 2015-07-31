#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
  multiset<string> names;
  string s;
  cin >> s;
  while(s != "."){
    names.insert(s);
    cin >> s;
  }
  
  for(multiset<string>::iterator i = names.begin(); i != names.end(); ++i)
    cout << *i << endl;
  
  return 0;
}
