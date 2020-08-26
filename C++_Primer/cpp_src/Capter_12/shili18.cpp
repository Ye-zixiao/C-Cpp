#include<iostream>
#include<vector>
#include<memory>
#include<string>
using namespace::std;

class Test {
public:
	Test():value(0){}
	Test(int val):value(val){}
	Test(const Test& item) :
		value(item.value) {
		cout << "Test(const Test&)" << endl;
	}


private:
	int value;
};

int main(void)
{
	vector<Test> tvec{ 1,2,3 };
	allocator<Test> talloc;

	cout << "---------------" << endl;
	const auto p = talloc.allocate(3);
	auto iter = p;
	for (decltype(tvec)::size_type i = 0; i < tvec.size(); ++i)
		talloc.construct(iter++, tvec[i]);
	while (iter != p) {
		talloc.destroy(--iter);
	}
	talloc.deallocate(p, 3);

	return 0;
}
