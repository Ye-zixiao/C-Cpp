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

	//��д����ֵ������ʱ��ñ�д�����Ա������һ�����ڴ���constexpr����һ�����ڴ�����ͨ����
	//��Ϊ��ʹ��������ֵ������Ҳ���Դ�������ͨ����
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
