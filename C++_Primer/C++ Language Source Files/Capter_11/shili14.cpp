#include<map>
#include<string>
#include<vector>
#include<iostream>
using namespace::std;

class Test {
	friend bool tcompare(const Test&, const Test&);
public:
	Test() = default;
	Test(int val,const string&s):
		value(val),str(s){}



private:
	int value;
	string str;
};

bool tcompare(const Test& lhs, const Test& rhs)
{
	return lhs.value < rhs.value;
}

int main(void)
{
	using pf = bool (*)(const Test&, const Test&);
	map<Test, size_t, pf> tmap(tcompare);
	//map中加入自定义的比较操作类型时，函数指针类型放在<>的最后面

	return 0;
}
