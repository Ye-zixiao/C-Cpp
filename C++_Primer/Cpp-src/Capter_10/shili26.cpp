#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace::std;

int main(void)
{
	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out(cout, " ");
	vector<int> ivec(in_iter, eof);
	sort(ivec.begin(), ivec.end());
	for (const auto i : ivec)out = i; cout << endl;

	return 0;
}
/*
另一种方式：
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace::std;

int main(void)
{
	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out(cout, " ");

	vector<int> ivec;
	copy(in_iter, eof, back_inserter(ivec));
	sort(ivec.begin(), ivec.end());
	for (const auto i : ivec)out = i; cout << endl;

	return 0;
}

*/
