#include<iostream>
using namespace::std;

struct A {
	A(int a) {
		cout << "A(int)" << endl;
	}
	A(short a) {
		cout << "A(short)" << endl;
	}
};

struct B {
	B(double a) {
		cout << "B(double)" << endl;
	}
};

void f(const A& a) {
	cout << "void f(A)" << endl;
}

void f(const B& a) {
	cout << "void f(B)" << endl;
}

int main(void)
{
	char c = 0;
	short s = 0;
	float fl = 0;
	double d = 0;
	int i = 0;
	long long ll = 0;
	long double ld = 0;
	long l = 0;

	f(c);
	f(s);
	f(fl);
	f(d);
	f(i);
	f(ll);
	f(ld);
	f(l);

	return 0;
}
