#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace::std;

class Test {
public:
	constexpr Test(int val=0):value(val){}

	int get(void) { return value; }
	Test& set(int value) { this->value = value; return *this; }

	//编写字面值常量类时最好编写两组成员函数，一组用于处理constexpr对象，一组用于处理普通对象
	//因为即使它是字面值常量类也可以创建出普通对象
	constexpr int get(void) const { return value; }

private:
	int value;
};

int main(void)
{
	Test test_1(10);
	cout << test_1.get() << endl;
	cout << test_1.set(23).get() << endl;

	constexpr Test test_2(24);
	cout << test_2.get() << endl;

	return 0;
}
