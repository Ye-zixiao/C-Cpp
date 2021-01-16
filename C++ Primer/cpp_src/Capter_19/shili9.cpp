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
void func(B&b){}/*�ڶ��ؼ̳е��У�������������ԣ���ת�����κ�һ�����඼��һ���õģ�
				���������func���䴫��һ��D������ǻᷢ�������Ե���*/

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
