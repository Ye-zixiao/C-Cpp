#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	constexpr unsigned rowCnt = 3, colCnt = 4;
	int iarr_2demension[rowCnt][colCnt];
	for (size_t i = 0; i != rowCnt; ++i)
		for (size_t j = 0; j != colCnt; ++j)
			iarr_2demension[i][j] = i * colCnt + j;

	for (const auto& row : iarr_2demension)
	{
		for (auto& col : row)//一个指向4元素数组的引用
			cout << col << ' ';//一个指向int元素的引用
		cout << endl;
	}

	cout << "-----------------------------" << endl;
	//for (auto row : iarr_2demension)//使用范围for循环时是除最内成循环外只能使用引用，而不能使用指针来遍历二维数组
	//	for (auto col : row)
	//		cout << *col << endl;
	for (const auto& row : iarr_2demension)
	{
		for (unsigned cnt = 0; cnt < colCnt; ++cnt)
			cout << row[cnt] << ' ';
		cout << endl;
	}

	int value = 10;
	const auto value_test = value;

	return 0;
}
