#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

bool is_prefix(const vector<int>& left, const vector<int>& right);

int main(void)
{
	vector<int> ivec_1{ 1,1,2,2,3,5,8,9 }, ivec_2{ 0,1,2,2,3,5,8 };
	cout << (is_prefix(ivec_1, ivec_2) ? "is prefix" : "not prefix") << endl;

	return 0;
}

bool is_prefix(const vector<int>& left, const vector<int>& right)
{
	if (left.size() > right.size())
		return is_prefix(right, left);//���ұߵ������Ƚϳ��������ҽ������������ڳ����в��õ���˭��˭�̵�����
	for (decltype(left.size()) i = 0; i != left.size(); ++i)
		if (left[i] != right[i])
			return false;
	return true;
}
