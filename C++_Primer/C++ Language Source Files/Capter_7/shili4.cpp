#include<iostream>
#include<string>
#include<vector>
//#include"header.h"
using namespace::std;

struct Test {
	Test() = default;
	Test(const string& str1, const string& str2,int init_value) :
		strvec{str1,str2},value(init_value){}
	vector<string> strvec;
	int value;
};

int main(void)
{
	Test test("hello", "world", 5);
	cout << test.strvec[0] << ' ' << test.strvec[test.strvec.size() - 1]
		<< ' ' << test.value << endl;
	Test tests;

	return 0;
}
