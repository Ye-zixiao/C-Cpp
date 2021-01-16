#include<iostream>
#include<typeinfo>
using namespace::std;

class A {
public:
	virtual ~A(){}
};

class B:public A{};
class C:public B{};

int main(void)
{
	C obj;
	A& ra = obj;
	cout << typeid(&ra).name() << endl;

	B* pb = new B;
	A& ra1 = *pb;
	cout << typeid(ra1).name() << endl;
	delete pb;

	return 0;
}
