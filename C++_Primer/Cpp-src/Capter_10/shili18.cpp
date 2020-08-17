#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace::std;

template<typename type>
ostream& operator<<(ostream& os, const vector<type>& tvec)
{
	for_each(tvec.begin(), tvec.end(), [&os](const type& t) {os << t << ' '; });
	return os;
}

int main(void)
{
	vector<int> ivec{ 1,-2,-3,4,5,-3,-7,-3,0 };
	//transform(ivec.begin(), ivec.end(), ivec.begin(), [](int i) {return i >= 0 ? i : -i; });
	transform(ivec.begin(), ivec.end(), ivec.begin(), [](int i)->int {if (i >= 0) return i; else return -i; });
	cout << ivec << endl;

	return 0;
}
