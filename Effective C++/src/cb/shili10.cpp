#include<iostream>

class Test {
	friend void std::swap<Test>(Test&, Test&);
public:
	Test(int v):pvalue(new int(v)){}
	Test(const Test&rhs):pvalue(new int(*rhs.pvalue)){}
	~Test() {
		if (pvalue) {
			std::cout << "yep,I get in" << std::endl;
			delete pvalue;
		}
	}

	int get(void) const {
		return pvalue ? *pvalue : -1;
	}

private:
	int* pvalue = nullptr;
};

namespace std {
	template<>//事实上并不推荐使用全特化的方式来解决swap对某一个特定类型的支持
	void swap<Test>(Test& lhs, Test& rhs) {
		swap(lhs.pvalue, rhs.pvalue);
	}
}

int main(void)
{
	Test lhs(13), rhs(53);
	std::cout << lhs.get() << ' ' << rhs.get() << std::endl;
	std::swap(lhs, rhs);
	std::cout << lhs.get() << ' ' << rhs.get() << std::endl;

	return 0;
}
