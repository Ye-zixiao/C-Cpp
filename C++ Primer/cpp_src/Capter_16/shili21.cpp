#include<iostream>
using namespace::std;

template<typename T>
struct Remove_reference {
	typedef T type;
};

template<typename T>
struct Remove_reference<T&> {
	typedef T type;
};

template<typename T>
struct Remove_reference<T&&> {
	typedef T type;
};


int main(void)
{
	int value;
	Remove_reference<decltype(32)> value1;
	Remove_reference<decltype((value))> value2;
	Remove_reference<decltype(std::move(value))> value3;

	return 0;
}
