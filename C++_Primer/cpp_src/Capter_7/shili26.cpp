#include<iostream>
#include<string>
//#include"Sales_data.h"
using namespace::std;

class Test {
public:
	Test() = default;
	//explicit Test(int val):value(val){}
	explicit Test(int val):value(val){}

	Test& operator=(const Test& item);
	int get_value(void) const { return value; }
private:
	int value;
};

Test& Test::operator=(const Test& item)
{
	value = item.value;
	return *this;
}

int main(void)
{
	Test test(10);
	test = Test(11);
	//����ͨ��explicit�ؼ��ֽ�������ʽ��ת�����캯����ֹ��
	//��Ȼexplicit�ؼ��֣���ȷ�ģ���ֹ����ʽ��ʹ��ת�����캯�����������ǿ���ͨ��һЩ�ֶ���ʽ�Ľ���ת��
	//���磺�ڴ�ת�������Ͷ�����һ��Ŀ�����͵�������Բ��������������ʹ��static_cast���и�Ϊ��ʽ��ת��
	cout << test.get_value() << endl;
    test=static_cast<Test>(12);
    cout<<test.get_value()<<endl;

	return 0;
}
