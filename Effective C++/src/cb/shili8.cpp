#include<iostream>
#include<string>
using namespace std;

class Test {
public:
	~Test() = default;
	Test(const Test&) = default;
	Test(Test&&)noexcept = default;
	Test& operator=(const Test&) = default;
	Test& operator=(Test&&)noexcept = default;

	string& get(void) { return str; }

	static Test* createTest(const string& s=string()) {
		return new Test(s);
	}

private:
	Test(const string&s):str(s){}
	string str;
};

int main(void)
{
	Test* ptest = Test::createTest("hello world");
	cout << ptest->get() << endl;
	Test test_mv = std::move(*ptest);
	cout << ptest->get() << ' ' << test_mv.get() << endl;

	delete ptest;

	return 0;
}
