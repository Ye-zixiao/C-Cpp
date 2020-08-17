#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace::std;

ostream& print(ostream& os,const vector<int>& ivec)
{
	for (const auto& i : ivec)
		os << i << ' ';
	return os;
}

int main(void)
{
	vector<int> ivec(10);
	for (size_t i = 0; i < ivec.size(); ++i)
		ivec[i] = i;
	print(cout, ivec) << endl;

	fill(ivec.begin(), ivec.begin() + ivec.size() / 2, 23);
	//ivec.begin()+ivec.size()/2是终点（但不包括它）
	print(cout, ivec) << endl;

	int new_value = 99;
	fill_n(ivec.begin() + ivec.size() / 2 , 3, new_value);
	print(cout, ivec) << endl;

	return 0;
}
