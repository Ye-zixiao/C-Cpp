#include<iostream>
#include<string>
//#include"Sales_data.h"
using namespace::std;

class Test {
public:
	Test() = default;
	//explicit Test(int val):value(val){}
	explicit Test(int val):value(val){}

	Test& operator=(const Test& item);
	int get_value(void) const { return value; }
private:
	int value;
};

Test& Test::operator=(const Test& item)
{
	value = item.value;
	return *this;
}

int main(void)
{
	Test test(10);
	test = Test(11);
	//可以通过explicit关键字将这种隐式的转换构造函数禁止掉
	//虽然explicit关键字（明确的）禁止了隐式的使用转换构造函数，但是我们可以通过一些手段显式的进行转换
	//比如：在待转换的类型对象用一个目标类型的名字用圆括号括起来或者使用static_cast进行更为显式的转换
	cout << test.get_value() << endl;
    test=static_cast<Test>(12);
    cout<<test.get_value()<<endl;

	return 0;
}
