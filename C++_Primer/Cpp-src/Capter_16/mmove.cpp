#include<iostream>
#include<vector>
#include<string>
#include<type_traits>
using namespace::std;

template<typename T>
auto mmove(T&& rvalue) ->typename remove_reference<T>::type&& {
	return static_cast<typename remove_reference<T>::type&&>(rvalue);
}

/*
1、若mmove函数实参是一个左值，T这就是左值引用类型了，rvalue是一个左值引用的右值引用，根据引用折叠的规则它会被折叠为一个左值引用，
	此时使用remove_reference会去除T的引用属性获得左值引用所指向的类型，并通过static_cast将rvalue左值引用强制转换为右值引用
2、若mmove函数实参本身就是一个右值，则返回的就是一个右值，不用特别的转换
*/

int main(void)
{
	string str = "hello world";
	string str_mv = mmove(str);
	//cout << str << ' ' << str_mv << endl;
	cout << str.size() << endl;
	cout << str_mv.size() << endl;

	return 0;
}
