#include<iostream>
#include<string>

namespace fuck {

template<typename T>
class Test {
public:
	Test(T v):value(v){}

	const T& get(void)const {
		return value;
	}
	Test& modified(T new_value) {
		value = new_value;
		return *this;
	}

private:
	T value;
};

}

int main(void)
{
	fuck::Test<int> itest(12);
	std::cout << itest.get() << std::endl;
	std::cout << itest.modified(32).get() << std::endl;

	return 0;
}
