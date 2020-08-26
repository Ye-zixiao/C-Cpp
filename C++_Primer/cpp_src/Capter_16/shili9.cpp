#include<iostream>
#include<string>
#include<vector>
#include<type_traits>
using namespace::std;

template<typename T>
auto func(T& container)->typename remove_reference<decltype(*container.begin())>::type {
	return *container.begin();
}

int main(void)
{
	vector<string> strvec{ "hello","world" };
	string str = func(strvec);
	remove_reference<decltype(*strvec.begin())>::type str_t = strvec.back();
	cout << str << endl;
	cout << str_t << endl;

	add_pointer<decltype(*strvec.begin())>::type pointer = &strvec.back();
	cout << *pointer << endl;

	remove_const<const string>::type strf = strvec.back();
	strf = "fuck";
	cout << strf;


	return 0;
}
