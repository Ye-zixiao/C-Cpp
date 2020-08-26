#include<iostream>
#include<string>
using namespace::std;

template<typename T,typename... Args>
void f(const T& t, const Args&... args) {
	cout << sizeof...(Args) << endl;
	cout << sizeof...(args) << endl;
}

int main(void)
{
	int i = 0; double d = 3.14; string s = "hello";
	f(i, d, s, 32);
	f(i, d, s);
	f(i, d);
	f(i);
	return 0;
}
