#include <iostream>

class A {
public:
  void f(double x){}
};

class B {
public:
  void f(int x, int y){}
};

class C : public A, public B {
  
  using A::f;
  using B::f;
public:
  void g(){
    using std::cout;
    using std::endl;
    f(42);
    A::f(42);
    cout << "hello" << endl;
  }
};

