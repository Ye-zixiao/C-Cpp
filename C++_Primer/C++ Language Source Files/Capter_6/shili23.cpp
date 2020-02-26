#include<iostream>
using namespace::std;

void f(void)
{
	cout << "f(void)" << endl;
}

void f(int)
{
	cout << "f(int)" << endl;
}

void f(int, int)
{
	cout << "f(int,int)" << endl;
}

void f(double, double v= 3.12)
{
	cout << "f(double,double=3.12)" << endl;
}

int main(void)
{
	//f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);

	return 0;
}
