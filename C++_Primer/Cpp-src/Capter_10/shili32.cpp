#include<iostream>
#include<vector>
#include<algorithm>
using namespace::std;

int main(void)
{
	vector<int> ivec(10);
	for (decltype(ivec)::size_type i = 0; i < ivec.size(); ++i)
		ivec[i] = i;

	for_each(ivec.crbegin(), ivec.crend(), [](int value) {cout << value << ' '; });
	cout << endl;

	for (auto iter = ivec.cend() - 1; iter != ivec.cbegin() ; --iter)
		cout << *iter << ' ';
	cout << *ivec.cbegin() << endl;

	return 0;
}

/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace::std;

int main(void)
{
	list<int> ilist{ 1,2,3,46,7,0,78,6 };
	auto zero_iter = find(ilist.crbegin(), ilist.crend(), 0);
	//cout << *zero_iter << endl;
	ilist.erase((++zero_iter).base());

	for_each(ilist.cbegin(), ilist.cend(), [](int value) {cout << value << ' '; });
	cout << endl;

	return 0;
}
*/
