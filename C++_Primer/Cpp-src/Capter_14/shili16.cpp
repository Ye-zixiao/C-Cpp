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

	A test1(a);//��һ����������
	A test2(b);//��һ����������
	A test3(c);//��һ����������
	A test4(d);//��һ����������
	A test5(e);//��������ת��
	A test6(g);//��������ת��

	A test;
	f(test);//��������ת��
	x(test);//��һ����������
	y(test);//��һ����������
	u(test);//��������ת��

	return 0;
}
