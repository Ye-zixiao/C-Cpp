#include<iostream>
#include<string>
//#include"Sales_data.h"
using namespace::std;

class Test {
public:
	Test() = default;
	Test(int val):value(val){}

	int get_value(void)const { return this->value; }
	//�������������ǿ���˳������ת�����캯��������ʱ������Ϊadd���β�
	//Test& add(const Test& item) { value += item.value; return *this;}
	//Test& add(Test item) { value += item.value; return *this; }

	//������ĺ����ǲ���˳������ת�����캯��������ʱ������Ϊadd���βΣ���������Ϊת�����캯�����ɵ���ʱ����������ֵ��ʽ�����βΣ���
	//Test& add(Test& item) { value += item.value; return *this; }

	//����Ȼ����Ȼʹ��ת�����캯�����ɵ���ʱ����������ֵ����ʽ��Ϊadd������ʵ�Σ����ǿ���ʹ����ֵ���õķ�ʽ��������ص���ʱ����
	Test& add(Test&& item) { value += item.value; return *this; }
private:
	int value;
};

int main(void)
{
	Test test(5);
	test.add(5);
	cout << test.get_value() << endl;

	return 0;
}
