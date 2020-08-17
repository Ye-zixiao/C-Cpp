#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

bool check_prefix(const vector<int>& ivec_short, const vector<int>& ivec_long);

int main(void)
{
	vector<int> ivec_1{ 0,1,2,2,3,5,8,9 }, ivec_2{ 0,1,2,2,3,5,8 };
	if (ivec_1.size() < ivec_2.size())
	{
		if (check_prefix(ivec_1, ivec_2))
			cout << "ivec_1 is the prefix of ivec_2" << endl;
		else
			cout << "ivec_1 is not the prefix of ivec_2" << endl;
	}
	else
	{
		if (check_prefix(ivec_2, ivec_1))
			cout << "ivec_2 is the prefix of ivec_1" << endl;
		else
			cout << "ivec_2 is not the prefix of ivec_1" << endl;
	}

	return 0;
}

bool check_prefix(const vector<int>& ivec_short, const vector<int>& ivec_long)
{
	for (vector<int>::const_iterator iter = ivec_short.cbegin(), long_iter = ivec_long.cbegin();
		iter != ivec_short.cend(); ++iter, ++long_iter)
		if (*iter != *long_iter)
			return false;
	return true;
}
