#include<iostream>
using namespace::std;

class Test {
	friend class UseTest;/*��ʱ�ͺ���һ����ĳ�Ա������Ϊ��Ԫ������ͬ��һ������߷ǳ�Ա������Ϊ��Ԫʱ������һ��Ҫ
	������߷ǳ�Ա����������������Ԫ�����ǰ������������ϵͳ��ٶ������Ԫİ���������ڵ�ǰ�������ǿɼ���*/
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
