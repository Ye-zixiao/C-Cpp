#include<iostream>
#include<string>
#define DEBUG

namespace nsp {
	template<typename T>
	class Test {
	public:
		Test(const T& t) :p(new T(t)) {}
		Test(const Test& rhs) :p(new T(*rhs.p)) {}
		~Test() {
			if (p)delete p;
		}

		T get(void)const {
			return p ? *p : T();
		}
		void swap(Test& rhs) noexcept {
			using std::swap;
			swap(p, rhs.p);
		}

	private:
		T* p = nullptr;
	};

	class Joker {
	public:
		Joker(const std::string&s):pstr(new std::string(s)){}
		Joker(const Joker& j) :pstr(new std::string(*j.pstr)){}
		~Joker() {
			if (pstr)delete pstr;
		}

		std::string get(void) const {
			return pstr ? *pstr : std::string("err");
		}
		void swap(Joker& rhs) {
			using std::swap;
			swap(pstr, rhs.pstr);
		}

	private:
		std::string* pstr = nullptr;
	};

	template<typename T>
	void swap(Test<T>& lhs, Test<T>& rhs) {
		lhs.swap(rhs);
	}

	void swap(Joker& lhs, Joker& rhs) {
		std::cout << "nsp::swap for Joker" << std::endl;
		lhs.swap(rhs);
	}
}

namespace std {
	//之所以定义它是为了防止nsp命名空间并没有为定义类型定义专属的非成员交换函数，这样全特化的std::swap可以作为备用防护
	template<>
	void swap<nsp::Joker>(nsp::Joker& lhs, nsp::Joker& rhs) {
		std::cout << "std::swap for Joker" << std::endl;
		lhs.swap(rhs);
	}
}

int main(void)
{
	using std::swap;
	nsp::Joker lhs("gsgs"), rhs("sfssf");
	std::cout << lhs.get() << " " << rhs.get() << std::endl;
	swap(lhs, rhs);
	std::cout << lhs.get() << " " << rhs.get() << std::endl;

	nsp::Test<int> tlhs(42), trhs(53);
	std::cout << tlhs.get() << " " << trhs.get() << std::endl;
	swap(tlhs, trhs);
	std::cout << tlhs.get() << " " << trhs.get() << std::endl;

	return 0;
}
