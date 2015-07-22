#include <iostream>
#include <typeinfo>

using namespace std;

int main(){
  const type_info& t = typeid("int");
  cout << t.name() << endl;
  return 0;
}