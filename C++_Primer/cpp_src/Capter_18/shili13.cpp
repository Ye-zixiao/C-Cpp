#include<iostream>

namespace nsp {

	class Test {
		friend void f(void);
		friend void func(const Test&);

	public:
		Test() = default;
	};

	void joker(const Test&);
}

int main(void)
{
	nsp::Test item;
	f();//函数f()由于没有形参，所以我们无法根据函数形参去到实参类型所在的命名空间去查找相应的函数
	func(item);//由于函数func()有一个形参，所以编译器会根据其函数实参到命名空间去查找相应的函数名字

	joker(item);

	return 0;
}
