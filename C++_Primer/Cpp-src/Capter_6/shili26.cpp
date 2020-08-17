#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
//#define NDEBUG
using namespace::std;

int add(int lvalue, int rvalue)
{
#ifndef NDEBUG
	cout << __func__ << ":";
#endif
	return lvalue + rvalue;
}

int sub(int lvalue, int rvalue)
{
#ifndef NDEBUG
	cout << __func__ << ":";
#endif
	return lvalue - rvalue;
}

int multi(int lvalue, int rvalue)
{
#ifndef NDEBUG
	cout << __func__ << ":";
#endif
	return lvalue * rvalue;
}

/*
int divi(int lvalue, int rvalue)
{
#ifndef NDEBUG
	cout << __func__ << ":";
#endif
	try {
		if (rvalue == 0)
			throw runtime_error("Second number can't be 0");
		return lvalue / rvalue;
	}
	catch (runtime_error err){
		cout << err.what() << "\n\treturn:";
		return 0;
	}
}
*/

//当然这个除法函数也可以使用条件运算符解决
int divi(int lvalue,int rvalue)
{
#ifndef NDEBUG
    cout<<__func__<<":";
#endif // NDEBUG
    return rvalue!=0?lvalue/rvalue:0;
}

int main(void)
{
	//vector<int (*)(int, int)> pf_vec;	//1、使用直接法定义：定义一个vector，其元素类型为函数指针、
	//vector<decltype(add)*> pf_vec;	//2、使用decltype让编译器自动去判别
	using PF = int (*)(int, int);		//3、使用类型别名定义
	vector<PF> pfvec{ add,sub,multi,divi };

	for (auto& pf : pfvec)
		cout << pf(10, 0) << endl;

	return 0;
}
