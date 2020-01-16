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
		Fibonacci,Lucas,Square,								/*类对象vector与普通的数组类型有着完全不同的特点：
																1、vector类对象的名字不是指针，而数组的名字是const指针；
																2、vector类对象不仅包括基本的数据类型，而且还包括了对这些
																内置的数据类型的操作，而普通数组没有；						*/
	};

	if (!Fibonacci.empty() && Fibonacci[1] == 2)			//类对象中不仅有基本的数据类型，而且还包括了一组与之关联的操作集
		cout << "Yes.\n";
	if (!seq_addrs[1].empty() && seq_addrs[1][1] == 3)
		cout << "Lucas is NB!\n";

	return 0;
}
