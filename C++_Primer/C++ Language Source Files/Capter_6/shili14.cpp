#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<initializer_list>
using namespace::std;

void print(int value);
void print(const string& str);

int main(void)
{
	double value = 1.23;
	void print(double value);//在局部作用域中声明void print(double value);会屏蔽外层的print函数声明
	print("hhe");

	return 0;
}

void print(int value)
{
	cout << value << endl;
}

void print(const string& str)
{
	cout << str << endl;
}

void print(double value)
{
	cout << value << endl;
}
