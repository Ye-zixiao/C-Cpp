#include<iostream>
#include<string>
#include<set>
using namespace::std;

class Test {
	//friend bool operator<(const Test&, const Test&);
	//friend bool operator==(const Test&, const Test&);
public:
	Test(const string&s):str(s){}

	int size(void)const { return str.size(); }
	string get(void)const {
		return str;
	}

private:
	string str;
};

//bool operator<(const Test& lhs, const Test& rhs) {
//	return lhs.size() < rhs.size();
//}
//
//bool operator==(const Test& lhs, const Test& rhs) {
//	return lhs.size() == rhs.size();
//}

bool compare_short(const Test& lhs, const Test& rhs) {
	return lhs.size() < rhs.size();
}

int main(void)
{
	int value{ 1 };
	cout << value << endl;
	multiset<Test, decltype(compare_short)*> test_set{ compare_short };
	test_set.insert(Test("hello"));
	test_set.insert(Test("hello"));
	test_set.insert(Test("hellos"));
	test_set.insert(Test("sho"));
	for (const auto& elem : test_set)
		cout << elem.get() << endl;

	return 0;
}
