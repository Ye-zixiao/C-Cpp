#include<iostream>

namespace nsp {
	class Test {
		friend std::ostream& operator<<(std::ostream&, const Test&);
		friend int getTest_value(const Test&);
		int value = 0;
	public:
		Test(int v):value(v){}
	};

	std::ostream& operator<<(std::ostream& os, const Test& t) {
		return os << t.value;
	}

	int getTest_value(const Test& t) {
		return t.value;
	}
}

int main(void)
{
	nsp::Test item(52);
	std::cout << item << std::endl;
	std::cout << getTest_value(item) << std::endl;

	return 0;
}
