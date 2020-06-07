#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
using namespace::std;
using namespace::placeholders;

int main(void)
{
	vector<string> strvec{
		"hello","world","","",
		"china","japan","joker",
		"","","doyoudo","",""
	};
	cout << count_if(strvec.begin(), strvec.end(), mem_fn(&string::empty))
		<< endl;
	cout << count_if(strvec.begin(), strvec.end(), bind(&string::empty, _1))
		<< endl;

	auto f = bind(&string::empty, _1);
	//生成的可调用对象使用(strvec.back().*p)()调用empty成员函数
	if (f(strvec.back()))
		cout << "empty" << endl;
	//生成的可调用对象使用(&strvec.back()->*p)()调用empty成员函数，其中这里的p指的是可调用对象保存的成员函数指针
	if (f(&strvec.back()))
		cout << "second empty" << endl;

	return 0;
}
