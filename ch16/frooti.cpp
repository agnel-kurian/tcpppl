#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class initial {
  char c;
public:
  initial(char c) : c(c) {}
  bool operator()(const string& s){
    return (s[0] == c);
  }
};

class initial_not {
  char c;
public:
  initial_not(char c) : c(c) {}
  bool operator()(const string& s){
    return (s[0] != c);
  }
};

void print(vector<string>::iterator vstart, vector<string>::iterator vend){
  for(vector<string>::iterator i = vstart; i != vend; ++i)
    cout << *i << endl;
}

int main(){
  string tooti[] = { "guava", "papaya", "jackfruit", "mashmelon", "watermelon",
    "grape", "pineapple", "apricot", "orange", "apple", "mango"
  };
  vector<string> frooti(tooti, tooti + sizeof(tooti) / sizeof(tooti[0]));
  
  print(frooti.begin(), frooti.end());
  cout << "-----" << endl;
  sort(frooti.begin(), frooti.end());
  print(frooti.begin(), frooti.end());
  cout << "-----" << endl;
  vector<string>::iterator pstart = find_if(frooti.begin(), frooti.end(),
    initial('g'));
  vector<string>::iterator pend = find_if(pstart, frooti.end(),
    initial_not('g'));

  print(pend, frooti.end());
  
  return 0;
}
