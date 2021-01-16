#include<iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std;

template<typename elemType, typename Comp = less<elemType> >			/*由于对于有些类型而言，如果没有typename Comp = less<elemType>，
																		执行这个类相关的函数时，默认会以为该类型是有相关的比较运算符的，
																		或者说<这个运算符对于这个类型是有效的。但是事实上不一定对于所有
																		的类型在语言上是有相关的比较运算符可以使用，而且也不能进行自定义
																		的比较。比如说我想比较两个字符串的长度，然而在语言上或者当前的库
																		中并没有相关的函数或者运算符可以调用。此时不能不引入第二个类模板
																		参数，并为其提供默认的参数，这样就可以将比较运算符从类定义从独立出来
																		用别的函数对象作为参数，重新赋予它新的比较功能
																		*/
class LessThanPred
{
public:
	LessThanPred(const elemType& val):_val(val) {}

	bool operator()(const elemType& val) const
	{
		Comp lesst;					//初始化列表无法转换成Comp
		return lesst(val, _val);
		/*return Comp(val, _val);*/
	}
	void val(const elemType& newval) { _val = newval; }
	elemType val() const { return _val; }

private:
	elemType _val;
};

class StringLess
{
public:
	bool operator()(const string& st1, const string& st2) const
	{
		return st1.size() < st2.size();
	}
};

int main(void)
{
	LessThanPred<int> lti(20);
	if (lti(11))
		cout << 11 << " less than " << lti.val() << endl;

	LessThanPred<string, StringLess> ltstr("moon");
	if (ltstr("hello"))
		cout << "hello" << " less than " << ltstr.val() << endl;
	else
		cout << "hello" << " not less than " << ltstr.val() << endl;

	return 0;
}
