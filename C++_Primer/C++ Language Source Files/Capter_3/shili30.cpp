#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	constexpr unsigned rowCnt = 3, colCnt = 3;
	int arr_2d[rowCnt][colCnt];
	int cnt = 0;
	for (auto& row : arr_2d)
		for (auto& col : row)
			col = cnt++;

	/*第一题、*/
	/*使用范围for循环输出二维数组*/
	for (const int (&row)[colCnt] : arr_2d)
	{
		for (const int &col : row)
			cout << col << ' ';
		cout << endl;
	}
	cout << "---------------------------------------" << endl;

	/*使用下标+普通的for循环输出二维数组*/
	for (size_t row = 0; row != rowCnt; ++row)
	{
		for (size_t col = 0; col != colCnt; ++col)
			cout << arr_2d[row][col] << ' ';
		cout << endl;
	}
	cout << "---------------------------------------" << endl;

	/*使用指向二维数组的指针和指向数组的指针输出二维数组*/
	for (const int(*parr_2d)[colCnt] = begin(arr_2d); parr_2d != end(arr_2d); ++parr_2d)
	{
		for (const int* parr_1d = begin(*parr_2d); parr_1d != end(*parr_2d); ++parr_1d)
			cout << *parr_1d << ' ';
		cout << endl;
	}
	cout << "---------------------------------------" << endl;

	/*第二题、适用类型别名来简化二维指针遍历二维数组的过程*/
	using int_arr = int[colCnt];
	for (const int_arr* parr_2d = begin(arr_2d); parr_2d != end(arr_2d); ++parr_2d)
	{
		for (const int* parr_1d = begin(*parr_2d); parr_1d != end(*parr_2d); ++parr_1d)
			cout << *parr_1d << ' ';
		cout << endl;
	}
	cout << "---------------------------------------" << endl;

	for (const int_arr& row : arr_2d)
	{
		for (const int& col : row)
			cout << col << ' ';
		cout << endl;
	}
	cout << "---------------------------------------" << endl;

	/*第三题、使用auto让编译器执行判定指针类型或者计数/下标类型*/
	for (const auto& row : arr_2d)
	{
		for (const auto& col : row)
			cout << col << ' ';
		cout << endl;
	}
	cout << "---------------------------------------" << endl;

	/*使用auto让编译器自行判断二维指针从而简化遍历二维数组的过程*/
	for (auto parr_2d = begin(arr_2d); parr_2d != end(arr_2d); ++parr_2d)
	{
		for (auto parr_1d = begin(*parr_2d); parr_1d != end(*parr_2d); ++parr_1d)//如果在auto前面加上const反而会让编译器认为const是在修饰变量名
			cout << *parr_1d << ' ';											//从而使得二维/一维指针具有顶层const的性质
		cout << endl;
	}

	return 0;
}
