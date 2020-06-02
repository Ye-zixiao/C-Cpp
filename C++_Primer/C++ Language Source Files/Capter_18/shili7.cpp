#include<iostream>
#include<string>
using namespace::std;

namespace nsp {
	namespace old_version {
		void func1(void) {
			cout << "old func1()" << endl;
		}
		void func2(void) {
			cout << "old func2()" << endl;
		}
		void func3(void) {
			cout << "old_but_inheritance_to_new func3()" << endl;
		}
	}

	inline namespace new_version {
		void func1(void) {
			cout << "new func1()" << endl;
		}
		void func2(void) {
			cout << "new func2()" << endl;
		}
		using old_version::func3;//在新版本中复用旧版本的func3函数
	}
}

int main(void)
{
	nsp::func1();
	nsp::func2();
	nsp::old_version::func1();
	nsp::old_version::func2();
	nsp::func3();

	return 0;
}
