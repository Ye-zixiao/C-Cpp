#include<iostream>
#include<iomanip>
using namespace::std;

int main(void)
{
	char ch;

	cin >> ch;
	ch = 'd';
	cin.unget();//�����һ���ַ��˻�
	cin >> ch;//�ֽ����и��˻ص��ַ����ж�ȡ�����
	cout << ch << endl;

	return 0;
}
