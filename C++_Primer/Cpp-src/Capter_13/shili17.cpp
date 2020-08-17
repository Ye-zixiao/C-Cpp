#include<iostream>
using namespace::std;

class Val {
	friend ostream& operator<<(ostream&os,const Val&);
public:
	Val(int v):value(v){}

	Val& operator=(const Val& rhs)& {
		value = rhs.value;
		return *this;
	}
	Val operator+(const Val& rhs) {
		return Val(this->value + rhs.value);
	}

private:
	int value;
};

ostream& operator<<(ostream& os, const Val& rhs) {
	return os << rhs.value;
}

int main(void)
{
	Val v1 = 10, v2 = 21;
	//(v1 + v2) = Val(32);
	//由于=重载时限定=拷贝运算符左侧对象必须是左值，所以向一个临时右值对象赋值是错误的
	cout << v1 << ' ' << v2 << endl;

	return 0;
}
