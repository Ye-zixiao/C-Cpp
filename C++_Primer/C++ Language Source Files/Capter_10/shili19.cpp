#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std::placeholders;
using namespace::std;

ostream& print(const int& value, ostream& os)
{
	return os << value << ' ';
}

int main(void)
{
	vector<int> ivec;
	for (decltype(ivec)::size_type i = 0; i < 10; ++i)
		ivec.push_back(i);

	for_each(ivec.begin(), ivec.end(), bind(print, _1, ref(cout)));
	cout << endl;

	return 0;
}
