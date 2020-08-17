#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace::std;

int main(void)
{
	vector<int> ivec(10);
	list<int> ilist;
	for (decltype(ivec)::size_type i = 0; i < ivec.size(); ++i)
		ivec.at(i) = i;

	copy(ivec.crbegin() + 2, ivec.crend() - 3, back_inserter(ilist));
	for (auto i : ilist)cout << i << ' '; cout << endl;

	return 0;
}
