#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace::std;

bool operator!=(const vector<int>& ivec, const list<int>& il)
{
	if (ivec.size() != il.size())
		return true;
	auto ivec_iter = ivec.cbegin();
	auto ilist_iter = il.cbegin();
	for (; ivec_iter != ivec.cend() && ilist_iter != il.cend(); ++ivec_iter, ++ilist_iter)
		if (*ivec_iter != *ilist_iter)
			return true;
	return false;
}

int main(void)
{
	vector<int> ivec1{ 1,2,3,4 };
	vector<int> ivec2{ 1,24,56,6 };
	if (ivec1 != ivec2)
		cout << "not equal" << endl;

	list<int> ilist{ 1,2,3,6 };
	if (ivec1 != ilist)
		cout << "not equal" << endl;

	return 0;
}
