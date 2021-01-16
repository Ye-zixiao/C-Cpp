#include<iostream>
#include<string>
using namespace::std;

struct Data {
	Data(int v) :value(v) {}
	int value;
};

template<typename T>
ostream& print(ostream& os, const T& tvalue) {
	return os << tvalue;
}

template<typename T, typename... Args>
ostream& print(ostream& os, const T& tvalue, const Args&... args) {
	//os << tvalue << ", ";
	//return print(os, args...);
	//这句表达式还可以通过这样的方法写：
	return print(os << tvalue << ", ", args...);
}

int main(void)
{
	string str("hello_world"); int value = 10; double dvalue = 3.14; Data data(23);
	print(cout, str, value, dvalue) << endl;
	//print(cout, str, value, data, dvalue) << endl;

	return 0;
}
