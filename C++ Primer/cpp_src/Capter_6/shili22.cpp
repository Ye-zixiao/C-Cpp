#include<iostream>
//#define NDEBUG
#include<cassert>
#include<string>
#include<vector>
using namespace::std;

void print_vector(vector<int>& ivec, size_t pos);

int main(void)
{
	vector<int> ivec(10);
	size_t cnt = 0;
	for (auto& i : ivec)
		i = cnt++;

	print_vector(ivec,10);
	return 0;
}

void print_vector(vector<int>& ivec, size_t pos)
{
	static size_t func_cnt = 0;
#ifndef NDEBUG
	cout << __func__ << " operatored " << ++func_cnt << " times! and at this time "
		<< " pos=" << pos << endl;
#endif
	if (pos > 0)
	{
		print_vector(ivec, pos - 1);
		cout << ivec[pos - 1] << ' ';
	}
	return;
}
