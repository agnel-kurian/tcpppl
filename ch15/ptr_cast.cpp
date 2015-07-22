#include <iostream>

using std::cout;
using std::endl;

template<class D, class S> D ptr_cast(S s){
  D dp = dynamic_cast<D>(s);
  if(dp == 0) throw std::bad_cast();
  return dp;
}

class A {
public:
  virtual void f() = 0;
};

class B : public A {
public:
  virtual void f(){ cout << "B" << endl; }
};

int main(){
  B b;
  A* pa = ptr_cast<A*>(&b);
  pa->f();
  return 0;
}