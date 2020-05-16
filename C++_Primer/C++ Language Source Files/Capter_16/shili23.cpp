#include<iostream>
#include<string>
#include<sstream>
//#define DEBUG
using namespace::std;

template<typename T>
string debug_rep(const T& t) {
	ostringstream oss;
	oss << t;
	return oss.str();
}

template<typename T>
string debug_rep(T* p) {
	ostringstream oss;
	oss << "pointer: " << p
		<< " " << (p ? *p : "null pointer");
	return oss.str();
}

template<>
string debug_rep(const char* p) {
#ifdef DEBUG
	cout << "special const char*p" << endl;
#endif
	return debug_rep(string(p));
}

template<>
string debug_rep(char* p) {
#ifdef DEBUG
	cout << "special char* p" << endl;
#endif
	return debug_rep(string(p));
}

int main(void)
{
	char pchar_arr[]={'h','e','l','l','o','\0'};
	const char* pcchar = "world";
	cout << debug_rep(pchar_arr) << endl << debug_rep(pcchar) << endl;
}
