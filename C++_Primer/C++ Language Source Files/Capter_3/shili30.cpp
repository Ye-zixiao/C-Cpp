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

	/*��һ�⡢*/
	/*ʹ�÷�Χforѭ�������ά����*/
	for (const int (&row)[colCnt] : arr_2d)
	{
		for (const int &col : row)
			cout << col << ' ';
		cout << endl;
	}
	cout << "---------------------------------------" << endl;

	/*ʹ���±�+��ͨ��forѭ�������ά����*/
	for (size_t row = 0; row != rowCnt; ++row)
	{
		for (size_t col = 0; col != colCnt; ++col)
			cout << arr_2d[row][col] << ' ';
		cout << endl;
	}
	cout << "---------------------------------------" << endl;

	/*ʹ��ָ���ά�����ָ���ָ�������ָ�������ά����*/
	for (const int(*parr_2d)[colCnt] = begin(arr_2d); parr_2d != end(arr_2d); ++parr_2d)
	{
		for (const int* parr_1d = begin(*parr_2d); parr_1d != end(*parr_2d); ++parr_1d)
			cout << *parr_1d << ' ';
		cout << endl;
	}
	cout << "---------------------------------------" << endl;

	/*�ڶ��⡢�������ͱ������򻯶�άָ�������ά����Ĺ���*/
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

	/*�����⡢ʹ��auto�ñ�����ִ���ж�ָ�����ͻ��߼���/�±�����*/
	for (const auto& row : arr_2d)
	{
		for (const auto& col : row)
			cout << col << ' ';
		cout << endl;
	}
	cout << "---------------------------------------" << endl;

	/*ʹ��auto�ñ����������ж϶�άָ��Ӷ��򻯱�����ά����Ĺ���*/
	for (auto parr_2d = begin(arr_2d); parr_2d != end(arr_2d); ++parr_2d)
	{
		for (auto parr_1d = begin(*parr_2d); parr_1d != end(*parr_2d); ++parr_1d)//�����autoǰ�����const�������ñ�������Ϊconst�������α�����
			cout << *parr_1d << ' ';											//�Ӷ�ʹ�ö�ά/һάָ����ж���const������
		cout << endl;
	}

	return 0;
}
