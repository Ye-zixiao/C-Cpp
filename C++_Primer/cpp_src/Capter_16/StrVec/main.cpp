#include<iostream>
#include<string>
#include"StrVec.h"
using namespace::std;

int main(void)
{
	StrVec strvec;
	strvec.emplace_back(12, 'c');
	strvec.push_back("hello");
	strvec.emplace_back(string("world"));
	for (const auto& elem : strvec)
		cout << elem << ' ';
	cout << endl;

	return 0;
}
