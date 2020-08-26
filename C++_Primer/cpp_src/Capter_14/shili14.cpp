#include<iostream>
#include<string>
using namespace::std;

struct B;

struct A {
	A() = default;
	A(const B& item) {
		cout << "A(const B&item)" << endl;
	}//A's constructor make:  B---->A

};

struct B {
	operator A() const {//B's memeber function make:   B---->A
		cout << "operator A() const" << endl;
		return A();
	}
};

void function(const A& item) {}

int main(void)
{
	const B item;
	//function(item);//引发B类型到A类型的类型转换到底要调用那个函数的歧义（二义性类型转换）
	function(A(item));//除非显式调用
	function(item.operator A());

	return 0;
}
