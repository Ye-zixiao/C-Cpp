#include<iostream>
using namespace std;

class Test {
public:
	auto func(void) const->void (Test::*)(void) {
		return &Test::hello;
	}

private:
	void hello(void) {
		cout << "hello world" << endl;
	}
};

int main(void)
{
	Test item;
	void (Test:: * pf)(void) = item.func();
	(item.*pf)();

	return 0;
}
