#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace::std;

class Test {
public:
	Test() = default;

	bool operator()(int value) {
		return !(value & 0x1);
	}
private:

};

int main(void)
{
	vector<int> ivec(10);
	Test test;
	for (decltype(ivec)::size_type i = 0; i < ivec.size(); ++i)
		ivec.at(i) = i;

	ostream_iterator<int> out(cout, " ");
	copy_if(ivec.cbegin(), ivec.cend(), out, test);
	cout << endl;

	return 0;
}
