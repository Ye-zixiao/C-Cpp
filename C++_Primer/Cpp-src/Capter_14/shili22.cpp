#include<iostream>
using namespace::std;

class Test {
public:
	Test(int v){}
};

class toInt {
public:
	operator int() const {
		return 1;
	}
};

void f(Test v){}

int main(void)
{
	short src_s = 0;
	toInt src;
	f(src);
	f(src_s);

	return 0;
}
