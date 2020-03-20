#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
//#include"Sales_data.h"
using namespace::std;

bool isFivech(const string& str)
{
	return str.size() >= 5;
}

int main(void)
{
	vector<string> strvec{ "hello","world","show","me","dolily","a" };
	auto iter_end = partition(strvec.begin(), strvec.end(), isFivech);
	strvec.erase(iter_end, strvec.end());
	for (const auto elem : strvec)cout << elem << ' '; cout << endl;

	return 0;
}
