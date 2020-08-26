#include<iostream>
#include<string>
using namespace::std;

template<typename T>
const T& debug_rep(const T& item) {
	cout << item << endl;
	return item;
}

template<typename T>
ostream& print(ostream& os, const T& tvalue) {
	return os << tvalue << ' ';
}

template<typename T,typename... Args>
ostream& print(ostream& os, const T& tvalue, const Args&... args) {
	os << tvalue << ' ';
	return print(os, args...);
}

template<typename... Args>
ostream& errmsg(ostream&os,const Args&...args) {
	return print(os, debug_rep(args)...);
}

int main(void)
{
	string str("hello_world"); int ivalue = 10; double dvalue = 2.34;
	errmsg(cout, ivalue, str, dvalue);

	return 0;
}
