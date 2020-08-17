#include<iostream>
#include<vector>
#include<numeric>
using namespace::std;

int main(void)
{
	vector<int> ivec(10);
	for (decltype(ivec)::size_type i = 0; i < ivec.size(); ++i)
		ivec.at(i) = i;

	cout << accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;

	return 0;
}
