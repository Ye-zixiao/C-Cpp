#include<iostream>
using namespace::std;

struct A {
	virtual ~A(){}

	void print_a(void) const {
		cout << "A" << endl;
	}
};

struct B :A {
	void print_b(void) const {
		cout << "B" << endl;
	}
};

struct C :B {
	void print_c(void) const {
		cout << "C" << endl;
	}
};

struct D :A, B {
	void print_d(void) const {
		cout << "D" << endl;
	}
};

void func(A&a){}
void func(B&b){}/*在多重继承当中，对于派生类而言，它转换到任何一个基类都是一样好的！
				所以这里的func向其传递一个D类对象是会发生二义性调用*/

int main(void)
{
	A* pa = new D();
	pa->print_a();
	if (B* pb = dynamic_cast<B*>(pa))
		pb->print_b();
	if (D* pd = dynamic_cast<D*>(pa))
		pd->print_d();
	delete pa;

	D item;
	func(item);

	return 0;
}
