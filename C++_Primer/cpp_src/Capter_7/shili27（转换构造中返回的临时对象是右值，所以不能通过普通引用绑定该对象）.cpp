#include<iostream>
#include<string>
//#include"Sales_data.h"
using namespace::std;

class Test {
public:
	Test() = default;
	Test(int val):value(val){}

	int get_value(void)const { return this->value; }
	//下面两个函数是可以顺利调用转换构造函数生成临时对象作为add的形参
	//Test& add(const Test& item) { value += item.value; return *this;}
	//Test& add(Test item) { value += item.value; return *this; }

	//而下面的函数是不能顺利调用转换构造函数生成临时对象作为add的形参，可能是因为转换构造函数生成的临时对象是以右值形式赋给形参？？
	//Test& add(Test& item) { value += item.value; return *this; }

	//但显然，虽然使用转换构造函数生成的临时对象是以右值的形式作为add函数的实参，但是可以使用右值引用的方式绑定这个返回的临时对象
	Test& add(Test&& item) { value += item.value; return *this; }
private:
	int value;
};

int main(void)
{
	Test test(5);
	test.add(5);
	cout << test.get_value() << endl;

	return 0;
}
