#include <iostream>

using std::cout;
using std::endl;

template<class T> class Vector;
//template<class T> class Vector {
//public:
//  Vector(){ cout << "Vector<T>" << endl; }
//};

template<> class Vector<void*> {
public:
  Vector(){ cout << "Vector<void*>" << endl; }
};

template<class T> class Vector<T*> {
  Vector<void*> vstar;
public:
  Vector(){ cout << "Vector<T*>" << endl; }
};

int main(){
  //Vector<int> v;
  Vector<void*> vstar;
  Vector<int*> tstar;
  return 0;
}

