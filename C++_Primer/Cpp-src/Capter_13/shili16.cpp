#include<iostream>
#include<vector>
#include"String.h"
using namespace::std;

int main(void)
{
	vector<String> strvec;
	for (size_t i = 0; i < 10; ++i)
	{
		strvec.push_back("hello");
		/*"hello"��String(const char*cp)��ת�����캯����ʼ����ʱ����ԭstrvec�е�Ԫ��ͨ���ƶ�����ķ�ʽ�ƶ���
		��ʱ����ͨ���ƶ����조���롱��������ڴ�λ�á��Ͼ������ʱ������һ����ֵ*/
		cout << i << "--------------------" << endl;
	}

	return 0;
}
