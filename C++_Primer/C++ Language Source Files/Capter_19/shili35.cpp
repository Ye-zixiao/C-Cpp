#include<iostream>
#include<string>
using namespace::std;

class Value {
public:
	using Bit = unsigned;
	enum state { NO = 0, RD = 1, WR = 2, ALL = 3 };
	Value(int v):value(v){}

	int read(void) const;
	void write(int);
	void set(state);

private:
	int value;
	Bit mode : 2;
};

int Value::read(void) const {
	if (mode & RD)return value;
	else {
		cerr << "You don't have the right to read this value" << endl;
		return 0;
	}
}

void Value::write(int new_value) {
	if (mode & WR)value = new_value;
	else cerr << "You don't have the right to write this value" << endl;
}

void Value::set(state m) {
	mode |= m;
}

int main(void)
{
	Value item(42);
	cout << item.read() << endl;
	item.set(Value::ALL);
	cout << item.read() << endl;
	item.write(84);
	cout << item.read() << endl;

	return 0;
}
