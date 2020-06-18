#include<iostream>
using namespace std;

class Test {
public:
	Test() = default;
	constexpr int getsc(void) const {
		return scvalue;
	}

	static const int* getscp(void) {
		return &scvalue;
	}

private:
	static constexpr int scvalue = 123;
};

constexpr int Test::scvalue;

int main(void)
{
	Test item;
	cout << item.getsc() << endl;
	cout << *item.getscp() << endl;

	return 0;
}
