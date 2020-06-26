#include<iostream>
#include<memory>
#include<string>
using namespace std;

class Test {
public:
	~Test() {
		if (pvalue && pstr) {
			cout << "~Test()" << endl;
			delete pvalue;
			delete pstr;
		}
	}

	static shared_ptr<Test> createTest(int v = 0, const string& s = string()) {
		//不能使用make_shared函数模板可能是因为make_shared不是该类的友元
		return shared_ptr<Test>(new Test(v, s));
	}

	int getval(void) { return *pvalue; }
	string& getstr(void) { return *pstr; }

	Test& build(int v = 0, const string& s = string()) {
		if (!pvalue && !pstr) {
			pvalue = new int(0);
			pstr = new string();
		}
		*pvalue = v;
		*pstr = s;
		return *this;

	}
	void close(void) {
		if (pvalue && pstr) {
			delete pvalue; pvalue = nullptr;
			delete pstr; pstr = nullptr;
		}
	}

private:
	int* pvalue = nullptr;
	string* pstr = nullptr;
	Test() = default;
	Test(int v,const string&s):
		pvalue(new int(v)),pstr(new string(s)){}
};

int main(int argc, char** argv)
{
	shared_ptr<Test> sptest = Test::createTest();
	sptest->build(341, "hello world");
	cout << sptest->getstr() << ' ' << sptest->getval() << endl;
	sptest->close();
	sptest->build(234, "world china");
	cout << sptest->getstr() << ' ' << sptest->getval() << endl;

	return 0;
}
