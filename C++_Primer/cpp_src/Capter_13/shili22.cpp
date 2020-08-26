#include<iostream>
using namespace::std;

class Test {
public:
	Test():value(0){}
	Test(int v):value(v){}

	int get(void) & {
		return value;
	}

private:
	int value;
};

Test f(void) {
	return Test(20);
}

Test& f(Test& i) {
	return i;
}

int main(void)
{
	Test test(10);
	cout << f(test).get() << endl;
	//cout << f().get() << endl;

	return 0;
}
