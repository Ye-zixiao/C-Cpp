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
	//function(item);//����B���͵�A���͵�����ת������Ҫ�����Ǹ����������壨����������ת����
	function(A(item));//������ʽ����
	function(item.operator A());

	return 0;
}
