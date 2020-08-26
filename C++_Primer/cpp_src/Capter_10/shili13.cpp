#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace::std;

int main(void)
{
	int value = 10;
	auto sum = [](int val_1, int val_2) {return val_1 + val_2; };
	//lamda表达式一般是匿名（或者说是无名的）的函数，但是这里还是可以给它取名字
	cout << (value=sum(11, 19)) << endl;

	auto addi = [value](int add) {return add + value; };
	cout << addi(15) << endl;

	return 0;
}
