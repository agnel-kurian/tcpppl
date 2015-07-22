class A {
public:
	virtual void f() {}
};

class B : public virtual A {
public:
	virtual void f() {}
};

class C : public virtual A {
public:
	virtual void f() {}
};

class D : public B, public C {
public:
};

int main(){
	return 0;
}

