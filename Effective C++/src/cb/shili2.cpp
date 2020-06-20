#include<iostream>
using namespace std;

class Test {
	friend ostream& operator<<(ostream&, const Test&);
	friend Test operator*(const Test&, const Test&);
	//friend const Test operator*(const Test&, const Test&);
	int value;
public:
	Test(int v):value(v){}
	Test& operator=(const Test& rhs)& {
		value = rhs.value;
		return *this;
	}
};

ostream& operator<<(ostream& os, const Test& item) {
	return os << item.value;
}

Test operator*(const Test& lhs, const Test& rhs) {
	return Test(lhs.value * rhs.value);
}

//const Test operator*(const Test& lhs, const Test& rhs) {
//	return Test(lhs.value, rhs.value);
//}

int main(void)
{
	Test lhs(32), rhs(3);
	cout << lhs * rhs << endl;
	//auto r = std::move(lhs * rhs);
	//(rhs * lhs) = rhs;

	return 0;
}
