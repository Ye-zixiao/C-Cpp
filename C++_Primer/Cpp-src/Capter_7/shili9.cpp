#include<iostream>
#include<string>
using namespace::std;

struct Teest {
	int value = 0;
public:
	Teest() = default;
	Teest(int init_value):
		value(init_value){}
	int get_value(void) const { return value; }
};

class Test {
	int value = 0;//��class�ж����ڵ�һ������˵����ǰ������ݳ�Ա��private��
public:
	Test() = default;
	Test(int init_value):
		value(init_value){}
	int get_value(void) const { return value; }
};

int main(void)
{
	Teest teest(9);
	cout << teest.get_value() << endl;
	cout << teest.value << endl;

	Test test(8);
	cout << test.get_value() << endl;
	//cout << test.value << endl;//

	return 0;

}
