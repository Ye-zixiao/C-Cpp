#include<iostream>
#include<string>
using namespace::std;

template<typename T1,typename T2>
class Test {
public:
	Test(T1 v1,T2 v2):
		value1(v1),value2(v2){}

	T1 get1(void) const { return value1;}
	T2 get2(void) const { return value2; }

private:
	T1 value1;
	T2 value2;
};

template<typename T1>
class Test<T1, string> {
public:
	Test(T1 v1,string str):
		value1(v1),value2(str){}

	T1 get1(void) const { return value1; }
	string get2(void) const { return value2; }

private:
	T1 value1;
	string value2;
};


int main(void)
{
	Test<int,string> item(1, "hello");
}
