#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;

int main(void)
{
	const int seq_size = 8;
	const int seq_cnt = 3;
	vector<int> Fibonacci(seq_size), Lucas(seq_size), Square(seq_size);
	Fibonacci = {
		1,2,3,5,8,13,21,
	};
	Lucas = {
		1,3,4,7,11,29,47,
	};
	Square = {
		1,4,9,16,25,36,49,64,
	};
	vector<int> seq_addrs[seq_cnt] = {
		Fibonacci,Lucas,Square,								/*�����vector����ͨ����������������ȫ��ͬ���ص㣺
																1��vector���������ֲ���ָ�룬�������������constָ�룻
																2��vector����󲻽������������������ͣ����һ������˶���Щ
																���õ��������͵Ĳ���������ͨ����û�У�						*/
	};

	if (!Fibonacci.empty() && Fibonacci[1] == 2)			//������в����л������������ͣ����һ�������һ����֮�����Ĳ�����
		cout << "Yes.\n";
	if (!seq_addrs[1].empty() && seq_addrs[1][1] == 3)
		cout << "Lucas is NB!\n";

	return 0;
}
