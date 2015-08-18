#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){
  typedef vector<string> svector;
  svector fruits;
  string fruit;
  while(cin >> fruit)
    if(fruit == ".")
      break;
    else
      fruits.push_back(fruit);
    
  for(svector::iterator i = fruits.begin(); i != fruits.end(); ++i)
    cout << *i << endl;
  return 0;
}

