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
	virtual void func() {}
};

class Y {
public:
	double dval;

	Y(double d) : dval(d) {}
	virtual void show() {}
};

class Z : public X, public Y {
public:
	int fuck;

	Z(int v, char c, double d, int f) :
		X(v, c), Y(d), fuck(f) {}
};//在fuck的后面有填充了4个字节

class W : public X, public Y {
public:
	int fuck;

	//这个虚函数的地址直接放在了第一基类X虚函数指针指向的虚函数表中
	virtual void shower() const {}
};

int main() {
	cout << "first base X: " << sizeof(X) << endl;
	cout << "second base Y: " << sizeof(Y) << endl;
	cout << "derived Z: " << sizeof(Z) << endl;
	cout << "derived W: " << sizeof(W) << endl;

	Z z(1, 2, 3.4, 5);

	printf("first base vptr: 0x%lx\n", *reinterpret_cast<long long *>(&z));
	printf("first base int: 0x%x\n", *reinterpret_cast<int *>((long long) &z + sizeof(long long)));
	printf("first base char: 0x%x\n", *reinterpret_cast<char *>((long long) &z + sizeof(long long)));
	printf("second base vptr: 0x%lx\n", *reinterpret_cast<long long *>((long long) &z + sizeof(X)));
	printf("second base double: %f\n", *reinterpret_cast<double *>((long long) &z + sizeof(X) + sizeof(long long)));
	printf("derived int: 0x%x\n", *reinterpret_cast<int *>((long long) &z + sizeof(X) + sizeof(Y)));

	return 0;
}