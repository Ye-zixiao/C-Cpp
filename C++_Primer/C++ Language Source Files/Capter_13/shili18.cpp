#include<iostream>
#include<vector>
#include<algorithm>
using namespace::std;

class Foo {
public:
	Foo() = default;
	Foo(const Foo&item):
		data(item.data){}

	void push_back(int val) {
		data.push_back(val);
	}

	Foo sorted(void)&& {
		cout << "Foo sorted(void)&&" << endl;
		sort(data.begin(), data.end());
		return *this;
	}
	/*Foo sorted(void)const& {
		cout << "Foo sorted(void) const &;" << endl;
		Foo temp(*this);
		sort(temp.data.begin(), temp.data.end());
		return temp;
	}*/
	Foo sorted(void) const& {
		cout << "Foo sorted(void) const &" << endl;
		return Foo(*this).sorted();
	}

	vector<int> data;
};

int main(void)
{
	Foo test;
	for (size_t i = 10; i > 0; --i)
		test.push_back(i);
	Foo ret = test.sorted();
	for (const auto& elem : ret.data)
		cout << elem << ' ';
	cout << endl;

	return 0;
}
