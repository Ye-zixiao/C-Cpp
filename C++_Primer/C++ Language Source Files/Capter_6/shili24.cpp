#include<iostream>
#include<string>
using namespace::std;

bool Bigger(const string& s1, const string& s2)//判断字符串中前者长度是否比后者大
{
	return s1.size() >= s2.size();
}

//第一种：使用指向函数的函数指针
const string& useBigger(const string& s1, const string& s2, bool (*pf)(const string&, const string&))
{
	if (pf(s1, s2))
		return s1;
	else return s2;
}

//第二种：函数类型的形参自动转换成指向函数的指针
/*const string& useSmaller(const string& s1,const string& s2,bool func(const string&,const string&))
{
    if(!func(s1,s2))
        return s1;
    else return s2;
}
*/

//第三种：使用类型别名使得函数指针的编写更为简洁
//using PFunc=bool (*)(const string&,const string&);
typedef bool (*PFunc)(const string&,const string &);
const string& useSmaller(const string &s1,const string& s2,PFunc pf)
{
    if(!pf(s1,s2))
        return s1;
    else return s2;
}

int main(void)
{
	//bool (*pf)(const string&, const string&) = Bigger;
	cout << useBigger("hello world", "show me the code", Bigger) << endl;
	cout << useSmaller("hello world","show me the code", Bigger) << endl;
	return 0;
}
