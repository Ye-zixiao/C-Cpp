#include<iostream>
#include<string>
#include<vector>
using namespace::std;

class Test {
public:
	Test(int value):
		value_3(value++),value_2(value++),value_1(value++){}
	//���ݳ�Ա��ʼ��˳�����������ඨ���еĳ���˳��һ�£�����value_1��Ȼ�ڹ��캯����ʼֵ�б��ĩβ����ȴ�ǵ�һ�����г�ʼ����
	vector<int> get_value(void)const { return { value_1,value_2,value_3 }; }

private:
	int value_1 = 0;
	int value_2 = 0;
	int value_3 = 0;
};

int main(void)
{
	Test test(1);
	vector<int>&& ref_value = test.get_value();
	for (const auto& elem : ref_value)
		cout << elem << ' ';
	cout << endl;

	return 0;
}
