#include<set>
#include<vector>
#include<iostream>
//#include<a>
using namespace::std;

set<int>& add_value(set<int>& iset)
{
	int value;
	while (cin >> value)
		iset.insert(value);
	return iset;
}

int main(void)
{
	vector<int> ivec;
	set<int> iset;
	for (decltype(ivec)::size_type i = 0; i < 10; ++i)
		ivec.push_back(i);


	add_value(iset);
	iset.insert(ivec.cbegin(), ivec.cend());

	for (const auto& i : iset)cout << i << ' '; cout << endl;

	return 0;
}
