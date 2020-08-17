#include"Vector.h"
#include<iostream>
#include<string>
#include<vector>
using namespace::std;

template<typename T>
void print(const T& container) {
	for (typename T::size_type i = 0; i < container.size(); ++i)
		cout << container[i] << ' ';
	cout << endl;
}

template<typename T>
void print_(T& container) {
	for (auto iter = container.begin(); iter != container.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;
}

template<typename T>
void print_v(const T& container) {
	for (typename T::const_iterator iter = container.cbegin(); iter != container.cend(); ++iter)
		cout << *iter << ' '; cout << endl;
}
int main(void)
{
	Vector<string> strvec{ "hello","world","fuck" };
	print(strvec);
	print_(strvec);

	vector<string> strv{ "hello","china","world" };
	print_v(strv);

	return 0;
}
