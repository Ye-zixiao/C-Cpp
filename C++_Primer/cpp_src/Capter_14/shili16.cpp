#include<iostream>
using namespace::std;

struct A {
	A() = default;
	A(int a){}
	A(double v){}

	operator short() const {
		return 1;
	}
	operator float() const {
		return 1;
	}
};

void f(long double v){}
void x(double v){}
void y(int v){}
void u(long long v){}

int main(void)
{
	bool a;
	char b;
	short c;
	float d;
	long long e;
	long double g;

	A test1(a);//有一个类型提升
	A test2(b);//有一个类型提升
	A test3(c);//有一个类型提升
	A test4(d);//有一个类型提升
	A test5(e);//都是算术转换
	A test6(g);//都是算术转换

	A test;
	f(test);//都是算术转换
	x(test);//有一个类型提升
	y(test);//有一个类型提升
	u(test);//都是算术转换

	return 0;
}
