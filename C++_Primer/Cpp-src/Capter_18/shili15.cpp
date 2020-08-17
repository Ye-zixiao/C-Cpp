/*
 *1、内层的名字隐藏外层的同名函数
*/

#include<iostream>
#include<string>

namespace nsp {
	void func(int value) {
		std::cout << "nsp::func" << std::endl;
	}
}

void func(int value){}
void test(void) {
	using nsp::func;//nsp::func隐藏了外层的func名字
	func(12);
}


/*
 *2、直接发生名字冲突
*/

#include<iostream>
#include<string>

namespace nsp {
	void func(int value) {
		std::cout << "nsp::func" << std::endl;
	}
}

void func(int value){}
using nsp::func;

int main(void)
{
	func(21);
	return 0;
}

/*
 *3、using声明同名但不同形参列表不会被认为是名字冲突，而是重载
*/

#include<iostream>
#include<string>

namespace nsp {
	void func(int value) {
		std::cout << "nsp::func" << std::endl;
	}
}

void func(void){}
using nsp::func;
//若使用using声明在同一个作用域中同名但不同形参列表就不会发生名字冲突

int main(void)
{
	func();
	return 0;
}


/*
 *4.1、using指示使得命名空间中的名字注入到最近作用域中造成名字冲突
*/

#include<iostream>
#include<string>

namespace nsp {
	void func(int value) {
		std::cout << "nsp::func" << std::endl;
	}
}

void func(int value) {}
void test(void) {
	using namespace::nsp;
	func(2);
	/*直接发生名字冲突，因为using指示将nsp命名空间中的func名字注入到了当前函数最近的作用域
	，若nsp命名空间中的名字与最近作用域中的名字同名且同形参列表则会发生名字冲突*/
}


/*
 *4.2、与上相同的问题
*/

#include<iostream>
#include<string>

namespace nsp {
	void func(int value) {
		std::cout << "nsp::func" << std::endl;
	}
}

void func(int value) {}
using namespace::nsp;
