#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace::std;

class Test {
	friend ostream& operator<<(ostream& os, const Test& item);
public:
	Test() = default;
	Test(int val,string s):
		value(val),str(s){}

	int get_value(void)const {
		return value;
	}
	string get_str(void)const {
		return str;
	}
private:
	int value;
	string str;
};

bool testcompare(const Test& lhs, const Test& rhs)
{
	return lhs.get_value() < rhs.get_value();
}

ostream& operator<<(ostream& os, const Test& item)
{
	return os << item.value << ' ' << item.str;
}

int main(void)
{
	Test test1(1, "hello"), test2(32, "world"), test3(-11, "show");
	using pf = bool (*)(const Test&, const Test&);
	set<Test, pf> store(testcompare);/*
	map<Test, pf, size_t> store_map(testcompare);
	++store_map[test1];*/
	store.insert(test2);
	store.insert(test1);
	store.insert(test3);

	for (const auto& elem : store)
		cout << elem << endl;
	cout << endl;
}
