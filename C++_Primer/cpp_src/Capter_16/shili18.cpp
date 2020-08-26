#include<iostream>
#include<string>
#include<cstring>
#include"Memory.h"
#include"Vector.h"
using namespace::std;

template<typename T>
int compare(const T& lhs, const T& rhs) {
	if (lhs < rhs)return -1;
	if (rhs < lhs)return 1;
	return 0;
}

template<size_t M,size_t N>
int compare(const char(&lref)[M], const char(&rref)[N]) {
	if (lref < rref)return -1;
	if (rref < lref)return 1;
	return 0;
}

template<>
int compare(const char* const& lpref, const char* const& rpref) {
	return strcmp(lpref, rpref);
}

int main(void)
{
	const char* lp = "hi", * rp = "world";
	cout << compare(lp, rp) << endl;

	cout << compare("hi", "show") << endl;

	return 0;
}
