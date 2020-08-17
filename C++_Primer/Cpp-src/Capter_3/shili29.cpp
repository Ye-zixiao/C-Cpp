#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	int arr_2dimesion[3][4];
	int cnt = 0;
	for (auto& row : arr_2dimesion)
		for (auto& col : row)
			col = cnt++;

	for (auto parr_2d = arr_2dimesion; parr_2d != arr_2dimesion + 3; ++parr_2d)//使用auto让编译器自行判断指向数组的指针
	{
		for (auto parr_1d = *parr_2d; parr_1d != *parr_2d + 4; ++parr_1d)
			cout << *parr_1d << ' ';
		cout << endl;
	}

	cout << "-------------------------------------" << endl;
	for (auto parr_2d = begin(arr_2dimesion); parr_2d != end(arr_2dimesion); parr_2d++)//使用begin/end函数来简化循环条件判断
	{
		for (auto parr_1d = begin(*parr_2d); parr_1d != end(*parr_2d); parr_1d++)
			cout << *parr_1d << ' ';
		cout << endl;
	}

	using int_arr = int[4];
	cout << "---------------------------------------" << endl;
	for (int_arr* parr_2d = begin(arr_2dimesion); parr_2d != end(arr_2dimesion); parr_2d++)//使用using别名来简化表示指向多维数组的指针
	{
		for (int* parr_1d = begin(*parr_2d); parr_1d != end(*parr_2d); ++parr_1d)
			cout << *parr_1d << ' ';
		cout << endl;
	}

	return 0;
}
