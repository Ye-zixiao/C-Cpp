#include<iostream>
using namespace::std;

class Test {
public:
	void f(int value) {}
	void f(double dvalue) = delete;
};

int main(void)
{
	Test test;
	test.f(10);
	test.f(12.2);

	return 0;
}
