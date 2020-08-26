#include<iostream>
#include<algorithm>
#include<string>
#include<memory>

class HasPtr {
	friend void swap(HasPtr& lhs, HasPtr& rhs);
	friend std::string& operator*(HasPtr& item);
public:
	HasPtr(const std::string&str=std::string()):
		pstr(new std::string(str)){}
	HasPtr(const HasPtr& rhs) {
		pstr = new std::string(*rhs.pstr);
	}
	~HasPtr() {
		delete pstr;
	}

	HasPtr& operator=(HasPtr rhs) {
		swap(*this, rhs);
		return *this;
	}

private:
	std::string* pstr;
};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
	std::cout << "void swap(HasPtr&lhs,HasPtr&rhs);" << std::endl;
	using std::swap;
	swap(lhs.pstr, rhs.pstr);
}

std::string& operator*(HasPtr& item)
{
	return *item.pstr;
}

int main(void)
{
	HasPtr hp1, hp2, hp3;
	hp1 = HasPtr("hello");
	hp2 = HasPtr("world");
	std::cout << *hp1 << ' ' << *hp2 << std::endl;

	return 0;
}
