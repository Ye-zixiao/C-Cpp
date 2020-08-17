#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace::std;

int main(void)
{
	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out(cout, " ");
	vector<int> ivec(in_iter, eof), final_vec;

	sort(ivec.begin(), ivec.end());
	unique_copy(ivec.begin(), ivec.end(), back_inserter(final_vec));
	for (const auto& i : final_vec)out = i; cout << endl;

	return 0;
}
