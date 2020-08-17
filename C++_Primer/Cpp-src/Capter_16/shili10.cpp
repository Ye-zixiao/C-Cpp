#include<iostream>
#include<string>
#include<utility>
using namespace::std;

void print(int&& rvalue, int& change) {
	cout << rvalue << ' ' << ++change << endl;
}

template<typename T1, typename T2, typename Fuc>
void f(T1&& value1, T2&& value2, Fuc ff) {
	ff(value1, value2);
}

/*
1.1）若函数实参是一个左值，那么函数模板的函数形参（原本是一个指向函数模板类型参数的右值引用）就因引用折叠而变成一个左值引用；
1.2）若函数实参是一个右值，那么函数模板的函数形参就会因为引用折叠的关系而而保持右值引用的属性

而由于无论是左值引用还是右值引用都是变量，其本质都是左值，所以若想将这个左值传递给内层的函数继续保持函数实参（左值或右值的属性），那么需要
使用forward转发函数

2.1）当一个左值引用交给forward，由于T是引用类型，那么forward会返回这个引用类型的右值引用，又根据引用折叠此时将会返回一个左值引用，故左值引用的属性继续保持；
2.2）当一个右值引用交给forward，由于此时的T是一个普通类型，那么forward接受这个右值引用但其本质是左值，forward会返回T的右值引用，故函数实参的右值引用属性继续保持，
若不使用forward，由于右值引用的本质是左值，所以当把这个右值引用试图传递给内层函数的普通类型右值引用形参显然是不行的，因为普通右值引用无法绑定到一个左值上

*/

template<typename T>
void infuc(T&& rvalue) {
	++rvalue;
}

template<typename T>
void func(T&& rvalue) {
	cout << rvalue << endl;
	infuc(rvalue);//此时rvalue是绑定到右值引用的右值引用，故还是右值引用
	cout << rvalue << endl;
}


void rever(int&& rvalue, int& lvalue) {
	cout << rvalue << ' ' << ++lvalue << endl;
}

template<typename T1, typename T2, typename Fuc>
void testfunc(T1&& v1, T2&& v2, Fuc inf) {
	cout << v1 << ' ' << v2 << endl;
	rever(std::forward<T2>(v2), std::forward<T1>(v1));
}

int main(void)
{
	int lvalue = 1002;
	testfunc(lvalue, 43, rever);/*此时，函数形参v1是左值引用，函数形参v2是右值引用，但形参两者本质上都是变量，都是左值
								*/

}
