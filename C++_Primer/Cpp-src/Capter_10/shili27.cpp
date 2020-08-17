#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
#include<list>
#include<algorithm>
using namespace::std;

int main(void)
{
	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out(cout, " ");
	vector<int> invec(in_iter, eof);
	list<int> ivec;
	unique_copy(invec.begin(), invec.end(), back_inserter(ivec));
	sort(ivec.begin(), ivec.end());

	for (const auto i : invec)out = i; cout << endl;
	for (const auto i : ivec)out = i; cout << endl;

	return 0;
}
