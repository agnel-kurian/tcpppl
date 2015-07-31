#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class initial {
  char i;
public:
  initial(char c) : i(c) {}
  bool operator()(const string& s){
    if(s.empty()) return false;
    return (s[0] == i);
  }
};
  


int main(){
  typedef vector<string> svector;
  svector fruits;
  string fruit;
  while(cin >> fruit)
    if(fruit == ".")
      break;
    else
      fruits.push_back(fruit);

  sort(fruits.begin(), fruits.end());
    
  //for(svector::iterator i = fruits.begin(); i != fruits.end(); ++i)
  //  cout << *i << endl;

  svector::iterator istart = find_if(fruits.begin(), fruits.end(), 
    initial('a'));
  svector::iterator iend = find_if(fruits.rbegin(), fruits.rend(), 
    initial('a')).base();
  if(istart == fruits.end() || iend == fruits.end()) return 0;
    
  for(svector::iterator i = istart; i != iend; ++i)
    cout << *i << endl;
    
  return 0;
}

