#include<iostream>
using namespace::std;

template<typename T>
inline int compare(const T& lhs, const T& rhs) {
	if (lhs < rhs)return -1;
	if (rhs < lhs)return 1;
	return 0;
}

class Test {
public:
	Test(int v):value(v){}

private:
	int value = 0;
};

int main(void)
{
	cout << compare(Test(1), Test(2)) << endl;

	return 0;
}
