#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace::std;

class Test {
public:
	Test(const string&str=""):
		name(str){}

	string get(void) const {
		return name;
	}

private:
	string name;
};

bool compare_test_p(Test* const& lhs, Test* const& rhs)
{
	return lhs->get().size() < rhs->get().size();
}

int main(void)
{
	vector<Test> tvec{ Test("hellodo"),Test("world"),Test("me"),Test("show") };
	set<Test*, decltype(compare_test_p)*> tset(compare_test_p);
	for (auto& elem : tvec)
		tset.insert(&elem);

	for (const auto& elem : tset)
		cout << elem->get() << ' ';
	cout << endl;

	return 0;
}
