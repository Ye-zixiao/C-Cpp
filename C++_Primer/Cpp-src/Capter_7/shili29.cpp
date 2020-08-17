#include<iostream>
using namespace::std;

class Test {
public:
	constexpr Test(int val):cvalue(val){}

	void set_value(int val) { cvalue = val; }
	constexpr int get_cvalue(void) const { return cvalue; }
private:
	int cvalue;
};

int main(void)
{
	Test test(10);
	cout << "(It is not constexpr object)\nbefore:" << test.get_cvalue() << endl;
	test.set_value(12);
	cout << "after:" << test.get_cvalue() << endl << endl;
	//int arr_1[test.get_cvalue()];
	/*��Ȼ������һ������ֵ�����࣬�����ⲻ��ζ������ͨ�ķ�ʽ��������ֵ��������������һ��constexpr����
	��ͬint���ͣ�int������ֵ���ͣ�һ�����������constexpr��ʼ��һ������������Ȼ������constexpr���󣻵�������
	constexpr�����Ҷ���ĳ�ʼ���ʽȷʵ���Ϲ�أ���һ���������ʽ����ô��ʱ�����Ķ������constexpr����
	*/

	cout<<"it is constexpr object!"<<endl;
	int value = 10;
	/*constexpr Test vtest(value);*/
	//constexprʹ�ñ��������ض���鶨��Ķ���Ľ���Ƿ����Ԥ�ڣ���һ��constexpr���������Ǿͻᱨ��
	//�����intǰ��constexprһ��
	//constexpr int vtest(value);//����Ҳ�ᱨ��

	constexpr Test ctest(10);
	cout << ctest.get_cvalue() << endl;
	int arr_2[ctest.get_cvalue()];

	return 0;
}
