#include<iostream>
#include<memory>
#include<string>
using namespace::std;

int main(void)
{
	int* pv = new int(32);
	{
		unique_ptr<int> pvalue(pv);
		*pv = 100;
		cout << *pvalue << endl;
	}
	cout << *pv << endl;//��Ȼ��һָ����������ָ��Ķ�̬���󣬵���ԭ��������ָ����Ȼָ����ڴ��
	//��g++�����������к�������һָ��������ʱ��û���ͷ���ָ����ڴ棬����˵��ԭ����ֵ��Ȼ����
	*pv = 102;
	cout << *pv << endl;

	return 0;
}
