#include<string>
#include<iostream>
#include<memory>
//#include<>
using namespace::std;

class HasPtr {
	friend string& operator*(HasPtr& item);
public:
	HasPtr(const string&str=string()):
		pstr(new string(str)),use(new size_t(1)){}
	HasPtr(const HasPtr&item):
        pstr(item.pstr),use(item.use){
            ++*use;
    }
	~HasPtr();

	HasPtr& operator=(const HasPtr& item);

private:
	string* pstr;
	size_t* use;
};

HasPtr::~HasPtr()
{
	if (-- * use == 0) {
		delete use;
		delete pstr;
	}
}

HasPtr& HasPtr::operator=(const HasPtr& item)
{
	++* item.use;
	if (-- * use == 0) {
		delete pstr;
		delete use;
	}
	use = item.use;
	pstr = item.pstr;
	return *this;
}

string& operator*(HasPtr& item)
{
	return *item.pstr;
}

int main(void)
{
	HasPtr hp("hello world");
	HasPtr hp_cpy = hp;
	hp = hp_cpy;
	cout << *hp_cpy << endl;

	return 0;
}
