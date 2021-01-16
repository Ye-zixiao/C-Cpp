#include<iostream>
#include<sstream>
#include<string>
using namespace::std;

template<typename T>
string debug_rep(const T& t) {
	ostringstream ret;
	ret << t;
	return ret.str();
}

template<typename T>
string debug_rep(T* p) {
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " string value: " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

//string debug_rep(const string& str) {
//	return '"' + str + '"';
//}

int main(void)
{
	string str("world");
	cout << debug_rep(str) << endl;
	cout << debug_rep(&str) << endl;
	const string* pstr = &str;
	cout << debug_rep(pstr) << endl;
}
