#include<iostream>
using namespace::std;

class Test {
	friend class UseTest;/*此时就和另一个类的成员函数作为友元函数不同。一个类或者非成员函数作为友元时，并非一定要
	该类或者非成员函数声明在声明友元的类的前面事先声明！系统会假定这个友元陌生的名字在当前作用域是可见的*/
public:
	Test() = default;
	Test(int val):
		value(val){}
	int get_value(void) const { return value; }
private:
	int value = 0;
};

class UseTest {
public:
	UseTest() = default;
	UseTest(int val):
		value(val){}
	int get_val(const Test& test) const { return value + test.value; }
private:
	int value = 0;
};

int main(void)
{
	Test test(9);
	UseTest usetest(10);
	cout<<usetest.get_val(test) << endl;

	return 0;
}
