//程序目的：编写一个函数，接收一个函数指针，直接返回该函数的引用
#include<iostream>
#include<string>
using namespace::std;

string strcat(const string& s1, const string& s2)
{
	return s1 + s2;
}

//第一种：使用类型别名
using PF = string(*)(const string&, const string&);
PF ret_pf1(PF pf)
{
	return pf;
}

//第二种：使用直接表示法（这种方法较为复杂点）
//函数名叫ret_pf2，该函数接收一个函数指针pf，返回一个函数指针，两个函数指针所指向的函数返回类型都是string，接收的参数为两个const string&
string (*ret_pf2(string(*pf)(const string&, const string&)))(const string&, const string&)
{
	return pf;
}

//第三种：使用尾置返回类型法，相较于直接法简洁很多
auto ret_pf3(string(*pf)(const string&, const string&))->string(*)(const string&, const string&)
{
	return pf;
}

int main(void)
{
	cout << strcat("hello ", "world") << endl;//1、直接调用
	cout << ret_pf1(strcat)("hello ", "world") << endl;//2、使用类型别名来简化函数指针的编写
	cout << ret_pf2(strcat)("hello ", "world") << endl;//3、使用直接法来编写内含函数指针的函数，较为复杂，也不容易理解
	cout << ret_pf3(strcat)("hello ", "world") << endl;//4、使用尾置返回类型法编写内含函数指针的函数，相较于直接法较为容易且也容易理解

	return 0;
}
