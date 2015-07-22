#include <iostream>

using namespace std;

class A {
  int x;
  //void f() = 0;
};

class B : public A {
  void f() { cout << "B" << endl; }
};

class C : public A {
  void f() { cout << "C" << endl; }
};

class D : public B, public C {
  void f() { cout << "D" << endl; }
};

int main(){
  D d;
  A* pd = &d;
  A *pa = dynamic_cast<A*>(pd);
  cout << pa << endl;
  return 0;
}
