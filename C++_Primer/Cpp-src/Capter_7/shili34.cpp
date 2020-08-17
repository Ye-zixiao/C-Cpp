#include<iostream>
#include<vector>
using namespace::std;

int multi=100;//but it is better to declare that constexpr

class Test {
public:
	Test() = default;
	static int get_value(void) { return value; }
	void set(int new_value) { value = new_value; }
	static void set_value(int new_value) { value = new_value*multi; }
	/*��̬��Ա��������ͨ��Ա���������������Ǿ�̬��Ա���Բ������ڶ����
	�����ظ�����������������е��ã���Ȼ�ⲻ����������������þ�̬��Ա�����Ͳ���ʵ�֣�
	��ͨ��Ա������ȻҲ���ԶԾ�̬���ݳ�Ա���ж�д���������ֶ�д���ñ��������ڶ��������ʱ
	�ſ���ʵ�֡���̬��Ա���������ڲ����ɾ�������ǰ���¾Ϳ���ʵ�ֵ��ã�
        ������Ҳ��ζ�ţ������˾�������������õľ�̬��Ա����ֻ�ܶ�ͬ����������
    ���������ڵľ�̬���ݳ�Ա�Լ����������Ӱ����������󣨱���ȫ�ֶ��󣩽��в���*/

private:
	static int value;
};

int Test::value = 10;

int main(void)
{
	Test test;
	cout << Test::get_value() << endl;
	cout << test.get_value() << endl;
	test.set(12);//��ͨ��Ա�����ĵ��ñ�����������������ʵ��
	cout << Test::get_value() << endl;
	Test::set_value(13);//��̬��Ա�������������ڶ���Ĵ��ڶ�ʵ�֣�����ͨ�����������������ֱ�ӵ���
	cout << test.get_value() << endl;

	return 0;
}
