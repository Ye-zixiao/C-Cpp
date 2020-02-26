#include<iostream>
#include<string>
using namespace::std;

class Test {
	friend int func(const Test&);//友元本身不一定需要在声明友元的类前面声明，只要友元声明中不出现新的（陌生的）名字，就可以不用声明
public:
	Test() = default;
	Test(int val):value(val){}
	int get_value(void)const;
private:
	int value = 0;
};

int func(const Test&item)		/*只要在类定义后面中，友元函数的声明或者定义出现在声明友元的类的成员函数的前面，成员函数就会认为友元函数是
								对其可见的*/
{
	return item.value;
}

int Test::get_value(void) const
{
	return func(*this);
}

int main(void)
{
	Test test(5);
	cout << test.get_value() << endl;

	return 0;
}
