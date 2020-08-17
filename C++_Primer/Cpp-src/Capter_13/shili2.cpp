#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<initializer_list>
using namespace::std;

class HasPtr {
public:
	HasPtr():pstr(nullptr),i(0){}
	HasPtr(const string&str,int val=0):
		pstr(new string(str)),i(val){}
	HasPtr(const HasPtr& item):
		pstr(new string(*item.pstr)),i(item.i){}
	~HasPtr() {
		delete pstr;
	}

	HasPtr& operator=(const HasPtr& item) {
		auto newp = new string(*item.pstr);
		delete pstr;
		pstr = newp;
		i = item.i;
		return *this;
	}

	string get(void) const {
		return pstr ? *pstr : "";
	}

private:
	string* pstr;
	int i;
};

int main(void)
{
	HasPtr p1("hello");
	HasPtr p2;
	p2 = p1;
	p2 = p2;
	cout << p2.get() << endl;

	return 0;
}
