#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<list>
#include<algorithm>
using namespace::std;

int main(void)
{
	vector<int> ivec{ 1,2,3,45,6,6,7,7,78,87,8,8,8 };
	list<int> ilist;

	sort(ivec.begin(), ivec.end());
	unique_copy(ivec.begin(), ivec.end(), back_inserter(ilist));
	for (auto i : ilist)cout << i << ' '; cout << endl;

	return 0;
}
