//Author: Ye-zixiao
//Date: 2021-03-06

#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <bits/stl_tree.h>
#include <initializer_list>
#include <iostream>
#include <queue>
#include <sstream>
#include <cmath>
using namespace std;

class X {
public:
	int value;
	char ch;

	X(int v, char c) : value(v), ch(c) {}
//	virtual void func() {}
};//8

class Y {
public:
	double dval;

	Y(double d) : dval(d) {}
	virtual void show() {}
};//16

class Z : public X, public Y {
public:
	int fuck;

	Z(int v, char c, double d, int f) :
		X(v, c), Y(d), fuck(f) {}
};//28后面可能填充4个字节

class W : public X, public Y {
public:
	int fuck;

	W(int v, char c, double d, int f) :
		X(v, c), Y(d), fuck(f) {}
	//这个虚函数的地址直接放在了第一基类X虚函数指针指向的虚函数表中
	virtual void shower() const {}
};//28后面，若继续生成一个单独派生类的vptr，那么就是28+8+4或者是交换了第一基类和第二基类
//使其28+4

int main() {
	cout << "first base X: " << sizeof(X) << endl;
	cout << "second base Y: " << sizeof(Y) << endl;
	cout << "derived Z: " << sizeof(Z) << endl;
	cout << "derived W: " << sizeof(W) << endl;

	W w(1, 2, 3.4, 5);

	//当一个派生类继承了一个没有虚函数的基类和一个有虚函数的基类后，它自己又定义了一个虚函数，
	//那么g++编译器就会将第一个没有vptr的基类与第二个具有vptr的基类进行交换，使得第二个基类
	//的vptr放置到类对象的首端，这样派生类对象就不需要为派生类的虚函数单独分配出一个vptr
	printf("second base double: %f\n", *reinterpret_cast<double *>((long long) &w + sizeof(void *)));

	return 0;
}