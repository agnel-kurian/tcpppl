#include <iostream>

using namespace std;

class A {
public:
  A(){
    cout << typeid(this).name() << endl;
  }
};

class B : public A {
public:
  B(){
    cout << typeid(this).name() << endl;
  }
};

class C : public B {
public:
  C(){
    cout << typeid(this).name() << endl;
  }
};

int main(){
  C c;
  return 0;
}
