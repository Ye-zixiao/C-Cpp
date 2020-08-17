#include<iostream>
#include<string>
using namespace::std;

struct A {
	A(int v){
		cout << "A(int)" << endl;
	}
	A(double v){
		cout << "A(double)" << endl;
	}
};

struct B {
	B(int a){
		cout << "B(int)" << endl;
	}
	/*B(float v) {
		cout << "B(double)" << endl;
	}
	B(double v) {
		cout << "B(double)" << endl;
	}*/
};

void f(const A&item){
	cout << "void f(const A&)" << endl;
}
void f(const B&item){
	cout << "void f(const B&)" << endl;
}

int main(void)
{
	short a = 0;
	float b = 0;
	long long c = 0;
	long double d = 0;
	bool e = 0;
	double s = 0;

	f(e);
	f(a);
	f(b);
	f(c);//long long��int��double��ת����������ת������׼ת���ȼ���ͬ������������ת��·�����A
	f(d);//
	f(s);

	return 0;
}
