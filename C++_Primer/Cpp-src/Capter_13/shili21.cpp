#include<iostream>
#include<utility>
using namespace::std;

class X {
public:
	X() = default;

	X(const X&item){}
	X(X&& item) = delete;

};

class Test {
public:
	Test() = default;

	Test(const Test&) = default;
	Test(Test&&) = default;

private:
	X x;
};


int main(void)
{
	Test test;
	Test test_copy = test;
	Test test_move = std::move(test);

	return 0;
}
