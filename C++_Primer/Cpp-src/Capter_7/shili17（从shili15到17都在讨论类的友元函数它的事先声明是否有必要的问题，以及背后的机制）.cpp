#include<iostream>
using namespace::std;

class Test {
	friend int UseTest::get_value(void);//若是把另一个类的成员函数当成友元函数，那么编译器必须要求该名字在前面被声明过
	//friend int get_value(void);//若是不同的非成员函数当友元函数，系统会认为该名字在当前作用域是可见的
public:
	Test() = default;
	Test(int val):value(val){}
	int get_value(void) const { return value; }

private:
	int value = 0;
};

class UseTest {
public:
	UseTest() = default;
	int get_value(void) { return 0; }

private:

};

int main(void)
{
	Test test(5);
	cout << test.get_value() << endl;
	return 0;
}
