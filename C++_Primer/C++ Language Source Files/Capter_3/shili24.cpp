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
	int arr_test[cnt];//cnt���ǳ������ʽ

	int arr_testtest[function()];
	int arr_tetst[function_2()];//��Ϊfunction_2��������һ��constexpr���������Է��ص�������һ���������ʽ

	char hello[] = "hello";
	for (auto c : hello)
		cout << c << ' ';
	cout << "end" << endl;


	return 0;
}
