#include<iostream>

class Test {
public:
	Test(int v) :pvalue(new int(v)) {}
	Test(const Test& rhs) :pvalue(new int(*pvalue)) {}
	~Test() {
		if (pvalue) {
			std::cout << "deleting..." << std::endl;
			delete pvalue;
		}
	}

	int get(void)const { return pvalue ? *pvalue : -1; }
	void swap(Test& rhs) {
		using std::swap;
		swap(pvalue, rhs.pvalue);
	}

private:
	int* pvalue = nullptr;
};

namespace std {
	//template<>
	//void swap<Test>(Test& lhs, Test& rhs) {
	//	//通过Test的成员函数来完成交换操作，而不是通过将std::swap的全特化版本设置为友元函数，降低封装性的方式来解决
	//	lhs.swap(rhs);
	//}
	template<>
	void swap(Test& lhs, Test& rhs) {
		lhs.swap(rhs);
	}
}

void func(void)noexcept {
	std::cout << "hello world" << std::endl;
	return;
}

int main(void)
{
	func();
	Test lhs(312), rhs(532);
	std::cout << lhs.get() << ' ' << rhs.get() << std::endl;
	std::swap(lhs, rhs);
	std::cout << lhs.get() << ' ' << rhs.get() << std::endl;
	return 0;
}
