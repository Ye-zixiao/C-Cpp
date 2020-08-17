#include<iostream>
#include<algorithm>
#include<string>
#include<memory>
#include<vector>

class HasPtr {
	friend void swap(HasPtr& lhs, HasPtr& rhs);
	friend std::string& operator*(HasPtr& item);
public:
	HasPtr(const std::string&str=std::string()):
		pstr(new std::string(str)),use(new size_t(1)){}
	HasPtr(const HasPtr& item):
		pstr(item.pstr),use(item.use){
		++* use;
	}
	~HasPtr() {
		if (-- * use == 0) {
			delete pstr;
			delete use;
			std::cout << "~HasPtr()" << std::endl;
		}
	}

	HasPtr& operator=(HasPtr rhs) {
		swap(*this, rhs);
		return *this;
	}

private:
	std::string* pstr;
	size_t* use;
};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.pstr, rhs.pstr);
	swap(lhs.use, rhs.use);
	std::cout << "void swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

std::string& operator*(HasPtr& item)
{
	return *item.pstr;
}

int main(void)
{
	HasPtr hp1("hello");
	HasPtr hp2("world");
	hp1 = hp2;
	std::cout << *hp1 << ' ' << *hp2 << std::endl;

	return 0;
}
