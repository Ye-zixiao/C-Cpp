#include<iostream>
#include<string>
#include"Share_ptr.h"
using namespace::std;

namespace nsp {
	void func(void)noexcept;

	namespace in_nsp {

		void func(void) noexcept;
	}
	inline namespace inline_nsp{
		void fun(void)noexcept {
			cout << "inline namespace" << endl;
		}
	}
}

void nsp::func(void) noexcept {
	cout << "hello world" << endl;
}

void nsp::in_nsp::func(void) noexcept {
	cout << "in_nsp->hello world" << endl;
}

namespace nsp {
	namespace inline_nsp {
		void inline_f(void) {
			cout << "inline_f" << endl;
		}
	}
}

namespace nsp::inline_nsp {
	void fff(void) {
		cout << "fff" << endl;
	}
}

int main(void)
{
	nsp::Share_ptr<string> sp(new string("hello"));
	cout << *sp << endl;
	cout << sp->size() << endl;

	nsp::func();
	nsp::in_nsp::func();
	nsp::fun();
	nsp::inline_f();
	nsp::fff();

	return 0;
}
