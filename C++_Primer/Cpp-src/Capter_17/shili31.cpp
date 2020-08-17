#include<iostream>
#include<iomanip>
using namespace::std;

int main(void)
{
	char ch;

	cin >> ch;
	ch = 'd';
	cin.unget();//把最后一个字符退回
	cin >> ch;//又将流中刚退回的字符进行读取并输出
	cout << ch << endl;

	return 0;
}
