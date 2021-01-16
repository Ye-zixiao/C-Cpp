#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

void init_arr(int* parr, const vector<int>& ivec, int size);

int main(void)
{
	int int_arr[] = { 1,2,3,4,5,6,7 };
	vector<int> ivec(begin(int_arr), end(int_arr));//ʹ�������ʼ��vector
	for (auto i : ivec)
		cout << i << ' ';
	cout << endl;

	constexpr unsigned size = 10;
	int copy_arr[size];
	init_arr(copy_arr, ivec, size);

	for (size_t i = 0; i < size; i++)
		cout << copy_arr[i] << ' ';
	cout << endl;

	return 0;
}

void init_arr(int* parr, const vector<int>& ivec,int size)
{
	for (unsigned cnt = 0; cnt < size; ++cnt)
	{
		if (cnt < ivec.size())//������ĳ���С���������ȣ���ô����������ǰ��Ĳ���ȥ��ʼ������
			parr[cnt] = ivec[cnt];
		else
			parr[cnt] = 0;  //������ĳ��ȴ����������ȣ���ô���ø������е�����Ԫ��ȥ��ʼ�����飬Ȼ������ĺ�벿����0��ʼ��
	}
}
