#include<iostream>
using namespace::std;

class Base {
public:
	virtual void func(void) {
		cout << "void Base::func(void)" << endl;
	}
};

class Derived1 :public Base {
public:
	void func(int v) {
		cout << "void Derived1::func(int v)" << endl;
	}
	using Base::func;//将基类中的虚函数实例加入到当前的派生类当中
	virtual void f2(void) {
		cout << "void Derived1::f2(void)" << endl;
	}
};

class Derived2 :public Derived1 {
public:
	void func(int v) {
		cout << "void Derived2:func(int v)" << endl;
	}

	void f2(void) {
		cout << "void Derived2::f2(void)" << endl;
	}
};

int main(void)
{
	Base base_obj;
	Derived1 derived_obj1;
	Derived2 derived_obj2;

	Base* p1 = &base_obj, * p2 = &derived_obj1, * p3 = &derived_obj2;
	p1->func();
	p2->func();
	p3->func();

	Derived1* pd1 = &derived_obj1;
	Derived2* pd2 = &derived_obj2;
	derived_obj1.func();
	//pd1->func();
	//p2->f2();
	pd1->f2();
	pd2->f2();

	Derived1* pd11 = &derived_obj2;
	Derived2* pd22 = &derived_obj2;
	//p3->func(10);
	pd11->func(21);
	pd22->func(21);

	return 0;

}
