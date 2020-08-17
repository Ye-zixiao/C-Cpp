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

constexpr int Class_in_initial::value;//���Ҫ��û���˾Ͳ����ˣ�����Ҫʹ�õ�����ȷ�о�̬��Աʵ��ĺ���

int main(void)
{
	Test test;
	cout << test.get_value() << endl;
	test.set_value(Class_in_initial::value);
	cout << test.get_value() << endl;

	return 0;
}
