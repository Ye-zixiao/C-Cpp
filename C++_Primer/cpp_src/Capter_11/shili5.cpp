#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace::std;

vector<int>& add_value(vector<int>& ivec)
{
	int value;
	while (cin >> value)
		if (find(ivec.cbegin(), ivec.cend(), value) == ivec.cend())
			ivec.push_back(value);
	return ivec;
}

int main(void)
{
	ostream_iterator<int> out(cout, " ");
	vector<int> ivec;
	add_value(ivec);
	sort(ivec.begin(), ivec.end());
	copy(ivec.cbegin(), ivec.cend(), out);

	return 0;
}
