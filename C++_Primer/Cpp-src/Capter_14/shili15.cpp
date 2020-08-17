#include<iostream>
using namespace::std;

struct A {
	A() = default;
	A(int v){
		cout << "A(int)" << endl;
	}
	A(double v){
		cout << "A(double)" << endl;
	}

	operator int() const {
		cout << "operator int() const" << endl;
		return 1;
	}
	operator double()const {
		cout << "operator double() const" << endl;
		return 1.2;
	}
};

void f(A v){}
void f2(long double v){}

int main(void)
{
	long double a = 0;
	//f(a);//因为A有两个分别接收double和int的转换构造函数，当接受一个long double的时候想将其转换成A类型就会操作二义性转换
	f(static_cast<int>(a));//可以使用显式强制转换达到目的
	f(static_cast<double>(a));

	A b;
	//f2(b);//因为A定义了两个分别可以转换成double和int的类型转换运算符，所以希望将其转换成long double的时候会造成二义性转换
	f2(b.operator double());
	f2(b.operator int());

	return 0;
}
