#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace::std;

int main(void)
{
	int value = 10;
	auto sum = [](int val_1, int val_2) {return val_1 + val_2; };
	//lamda���ʽһ��������������˵�������ģ��ĺ������������ﻹ�ǿ��Ը���ȡ����
	cout << (value=sum(11, 19)) << endl;

	auto addi = [value](int add) {return add + value; };
	cout << addi(15) << endl;

	return 0;
}
