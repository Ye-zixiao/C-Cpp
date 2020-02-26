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
	//对于偶数个数列而言是中间右边的那个数，对于奇数个数列而言正好是中间那个数

	while (mid != end && *mid != sought)//检查*mid是否与寻找的数相等
	{
		cout << *mid << ' ';
		if (sought < *mid)				//检查寻找的数是否小于*mid
			end = mid;
		else
			beg = mid + 1;				//检查寻找的数是否大于*mid
		mid = beg + (end - beg) / 2;
	}
	cout << *mid << endl;

	if (*mid == sought)
		return true;
	else
		return false;
}
