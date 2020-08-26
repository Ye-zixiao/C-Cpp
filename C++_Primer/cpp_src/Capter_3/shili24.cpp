#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace::std;

constexpr int function(void)
{
	return 10;
}

const int function_2(void)
{
	return 10;
}

int main(void)
{
	const int size = 10;
	constexpr unsigned int const_size = 10;
	int arr[size];
	int array[const_size];

	unsigned int cnt = 10;
	int arr_test[cnt];//cnt不是常量表达式

	int arr_testtest[function()];
	int arr_tetst[function_2()];//因为function_2函数不是一个constexpr函数，所以返回的数不是一个常量表达式

	char hello[] = "hello";
	for (auto c : hello)
		cout << c << ' ';
	cout << "end" << endl;


	return 0;
}
