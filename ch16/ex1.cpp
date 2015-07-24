#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> cvector;

int main(){
  cvector v;
  for(char c = 'a'; c <= 'z'; ++c)
    v.push_back(c);

  for(cvector::iterator i = v.begin(); i != v.end(); ++i)
    cout << *i << endl;
  
  cout << "---" << endl;
  
  for(cvector::reverse_iterator i = v.rbegin(); i != v.rend(); ++i)
    cout << *i << endl;
  
  return 0;
}