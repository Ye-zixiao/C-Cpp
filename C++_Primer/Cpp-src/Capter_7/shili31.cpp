#include<iostream>
#include<string>
using namespace::std;

class Test {
public:
	Test() = default;

	static double get_sdvalue(void) { return sdvalue; }
	static int get_svalue(void) { return svalue; }

	/*����̬���ݳ�Ա�ڱ�������б��������������ֵ�滻����Ȼ�޴��������£�����������
	������ͳ�ʼ����̬���ݳ�Ա�����ǵ������к����õ���̬���ݳ�Ա��Ҫ���ʣ�ͨ�����û���ָ�룩
	��ʱ��ͱ�����������о�̬��Ա����ͳ�ʼ��*/
	void test(const int &ref_svalue=svalue){}
	//void test(const int *p_svalue=&svalue){}

private:
	static constexpr double sdvalue = 1.23;
	static constexpr int svalue = 10;
	int arr[svalue];
};


constexpr int Test::svalue;
constexpr double Test::sdvalue;

int main(void)
{
	cout << Test::get_sdvalue() << endl;
	cout << Test::get_svalue() << endl;
	Test test;
	test.test();

	return 0;
}
