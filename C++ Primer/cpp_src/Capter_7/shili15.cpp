#include<iostream>
#include<string>
using namespace::std;

class Test {
	friend int func(const Test&);//��Ԫ����һ����Ҫ��������Ԫ����ǰ��������ֻҪ��Ԫ�����в������µģ�İ���ģ����֣��Ϳ��Բ�������
public:
	Test() = default;
	Test(int val):value(val){}
	int get_value(void)const;
private:
	int value = 0;
};

int func(const Test&item)		/*ֻҪ���ඨ������У���Ԫ�������������߶��������������Ԫ����ĳ�Ա������ǰ�棬��Ա�����ͻ���Ϊ��Ԫ������
								����ɼ���*/
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
