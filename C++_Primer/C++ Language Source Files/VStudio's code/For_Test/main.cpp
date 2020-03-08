#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace::std;

int main(void)
{
	vector<int> ivec;
	ivec.resize(10);
	fill_n(ivec.begin(), ivec.size(), 10);
	for (auto i : ivec)cout << i << ' '; cout << endl;

	auto iter = back_inserter(ivec);

	return 0;
}