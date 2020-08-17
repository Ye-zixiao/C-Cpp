#include<iostream>
#include<algorithm>
#include<string>

struct Test {
	Test() = default;
	Test(const std::string&s):str(s){}
	std::string str;
};

struct withTest {
	Test ts;
	withTest() = default;
	withTest(const std::string&s):ts(s){}
};

void swap(Test& lhs, Test& rhs) {
	using std::swap;
	swap(lhs.str, rhs.str);
}

void swap(withTest& lhs, withTest& rhs) {
	//std::swap(lhs.ts, rhs.ts);
	//使用标准库中swap还是能够成功，因为标准库采用的是函数模板采用编译合成的移动赋值运算符对Test对象lhs和rhs进行交换
	using std::swap;
	swap(lhs.ts, rhs.ts);

}

int main(void)
{
	withTest item1("htllow"), item2("itemsgf");
	std::cout << item1.ts.str << ' ' << item2.ts.str << std::endl;
	swap(item1, item2);
	std::cout << item1.ts.str << ' ' << item2.ts.str << std::endl;
	return 0;
}
