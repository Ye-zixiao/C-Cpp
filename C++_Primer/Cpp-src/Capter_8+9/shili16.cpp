#include<string>
#include<iostream>
#include<list>
#include<vector>
using namespace::std;

class Test {
public:
	Test() = default;
	Test(int val):value(val){}

	int get(void)const { return value; }
	const Test& set(int val) { value = value; return *this; }

private:
	int value;
};

int main(void)
{
	vector<Test> tvec;
	for (size_t i = 0; i < 5; ++i)
		tvec.emplace_back(i);

	for (const Test& elem : tvec)
		cout << elem.get() << ' ';
	cout << endl;

	return 0;
}
