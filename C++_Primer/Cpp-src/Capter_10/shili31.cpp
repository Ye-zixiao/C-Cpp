#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace::std;

int main(void)
{
	string str("hello,world,china");
	auto comma = find(str.cbegin(), str.cend(), ',');
	cout << string(str.cbegin(), comma) << endl;

	auto rcomma = find(str.crbegin(), str.crend(), ',');
	cout << string(rcomma.base(), str.cend()) << endl;

	return 0;
}
