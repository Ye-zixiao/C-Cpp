#include<iostream>
#include<memory>
//#include"Blob.h"
using namespace::std;

void func1(void) noexcept{}
void func2(void) throw(){}
void func3(void) noexcept(false){}
void func4(void) noexcept(true){}
void func5(void){}

struct Test {
	void function(void) const noexcept(false){}
	void func_throw(void) noexcept {
		//throw runtime_error(":");
	}
};

int ret(void) { return 1; }
constexpr int cret(void) { return 1; }

void dynamic_func(void) throw(){}//动态异常说明，throw()表明不会抛出异常，作为表达式的话就是动态异常表达式的潜在异常集合为空
void dynamic_func_throw(void) throw(int){}//动态异常说明，表示可能会抛出一个int类型的异常对象，作为表达式的话就是表达式的潜在异常集合为空

int main(void)
{
	cout << boolalpha;
	cout << noexcept(func1()) << endl;
	cout << noexcept(func2()) << endl;
	cout << noexcept(func3()) << endl;
	cout << noexcept(func4()) << endl;
	cout << noexcept(func5()) << endl;

	Test test;
	int value = 10;
	constexpr int cvalue = 10;
	test.function();
	test.func_throw();
	cout << noexcept(test.func_throw()) << endl;
	cout << noexcept(ret()) << endl;
	cout << noexcept(cret()) << endl;
	cout << noexcept(cvalue) << endl;
	cout << noexcept(value) << endl;

	//检查表达式的潜在异常集合是否为空
	cout << "dynamic express:" << endl;
	cout << noexcept(dynamic_func()) << endl;
	cout << noexcept(dynamic_func_throw()) << endl;

	cout << sizeof(cret()) << endl;
	cout << sizeof(ret()) << endl;


	return 0;
}
