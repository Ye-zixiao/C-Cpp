#include<iostream>
using namespace::std;

class Test {
	friend int UseTest::get_value(void);//���ǰ���һ����ĳ�Ա����������Ԫ��������ô����������Ҫ���������ǰ�汻������
	//friend int get_value(void);//���ǲ�ͬ�ķǳ�Ա��������Ԫ������ϵͳ����Ϊ�������ڵ�ǰ�������ǿɼ���
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
