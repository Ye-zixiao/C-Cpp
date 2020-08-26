#include<iostream>
#include<string>
using namespace::std;

class Test {
public:
	Test() :value(0){}

	void set_value(const int& val) { value = val; }
	int get_value(void)const { return value; }

private:
	int value;

};

class Class_in_initial {
public:
	static constexpr int value = 10;
};

constexpr int Class_in_initial::value;//这句要是没有了就不行了，对于要使用到具有确切静态成员实体的函数

int main(void)
{
	Test test;
	cout << test.get_value() << endl;
	test.set_value(Class_in_initial::value);
	cout << test.get_value() << endl;

	return 0;
}
