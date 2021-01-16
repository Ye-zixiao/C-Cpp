#include<iostream>
#include<algorithm>
#include<string>
#include<memory>
#include<vector>

class HasPtr {
	friend void swap(HasPtr& lhs, HasPtr& rhs);
	friend std::string& operator*(HasPtr& item);
	friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
	friend const std::string& operator*(const HasPtr& item);
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

const std::string& operator*(const HasPtr& item)
{
	return *item.pstr;
}

bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
	return (*lhs.pstr).size() < (*rhs.pstr).size();
}

int main(void)
{
	std::vector<HasPtr> hpvec{ HasPtr("world"),HasPtr("show"),HasPtr("me") };
	//std::cout << std::endl;
	std::sort(hpvec.begin(), hpvec.end());
	//std::cout << std::endl;
	for (const auto& elem : hpvec)
		std::cout << *elem << ' ';
	std::cout << std::endl;

	return 0;
}
