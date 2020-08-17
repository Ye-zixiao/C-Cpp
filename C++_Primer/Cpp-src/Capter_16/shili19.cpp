#include<iostream>
#include<string>
#include<unordered_set>

template<typename> class std::hash;


class Test {
	friend bool operator==(const Test&, const Test&);
	friend class std::hash<Test>;
public:
	Test() = default;
	Test(int v,const std::string&s):
		value(v),str(s){}

	int getvalue(void) const { return value; }
	std::string getstr(void) const { return str; }

private:
	int value = 0;
	std::string str;
};

bool operator==(const Test& lhs, const Test& rhs) {
	return lhs.getstr() == rhs.getstr() && lhs.getvalue() == rhs.getvalue();
}

namespace std {

template<>
class hash<Test> {
public:
	typedef size_t result_type;
	typedef Test argument_type;
	size_t operator()(const Test& test) const;
};

size_t hash<Test>::operator()(const Test& test)const {
	return hash<string>()(test.getstr()) ^ hash<int>()(test.getvalue());
}

}

int main(void)
{
	std::unordered_set<Test> test_set;
	test_set.insert(Test(12, "world"));
	test_set.insert(Test(22, "show"));
	for (const auto& elem : test_set)
		std::cout << elem.getstr() << ' ' << elem.getvalue() << std::endl;
	return 0;
}
