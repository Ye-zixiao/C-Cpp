#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>
using namespace::std;

ostream& operator<<(ostream& os, const vector<int>& ivec)
{
	for (auto i : ivec)
		os << i << ' ';
	return os;
}

ostream& operator<<(ostream& os, const list<int>& ilist)
{
	for (auto i : ilist)
		os << i << ' ';
	return os;
}

int main(void)
{
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	vector<int> back_ivec, inserter_ivec;
	list<int> front_list;

	copy(ivec.begin(), ivec.end(), back_inserter(back_ivec)); cout << back_ivec << endl;
	copy(ivec.begin(), ivec.end(), front_inserter(front_list)); cout << front_list << endl;
	copy(ivec.begin(), ivec.end(), inserter(inserter_ivec, inserter_ivec.end())); cout << inserter_ivec << endl;

	return 0;
}
