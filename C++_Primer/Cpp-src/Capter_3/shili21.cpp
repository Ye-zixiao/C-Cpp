#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace::std;

void print(const vector<int>& v);
bool find_sought(const vector<int>& ivec, int sought);

int main(void)
{
	vector<int> ivec(10);
	int num = 0;
	for (auto& i : ivec)
	{
		i = num;
		num += 3;
	}
	print(ivec);

	int sought;
	cin >> sought;
	if (find_sought(ivec, sought))
		cout << "find " << sought << endl;
	else
		cout << "not find " << sought << " in this vector" << endl;

	return 0;
}

void print(const vector<int>& v)
{
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	return;
}

bool find_sought(const vector<int>& ivec, int sought)
{
	auto beg = ivec.begin(), end = ivec.end();//0 1 2 3  4  5  6  7  8  9
	auto mid = ivec.begin() + (end - beg) / 2;//0 3 6 9 12 15 18 21 24 27
	//����ż�������ж������м��ұߵ��Ǹ������������������ж����������м��Ǹ���

	while (mid != end && *mid != sought)//���*mid�Ƿ���Ѱ�ҵ������
	{
		cout << *mid << ' ';
		if (sought < *mid)				//���Ѱ�ҵ����Ƿ�С��*mid
			end = mid;
		else
			beg = mid + 1;				//���Ѱ�ҵ����Ƿ����*mid
		mid = beg + (end - beg) / 2;
	}
	cout << *mid << endl;

	if (*mid == sought)
		return true;
	else
		return false;
}
