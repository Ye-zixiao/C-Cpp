#include<iostream>
#include<stack>
#include<string>
#define NDEBUG//Ҫ��RPN.hǰ�涨�����Ч
#include"RPN.h"
using namespace::std;

int main(void)
{
	RPN expr1("3*54-100/(23-3)");
	cout << expr1.get_expr() << " convert to: " << expr1.get_OperandStack_cp() << endl;
	expr1.set_expr_str("3*4/90+100");
	cout << expr1.get_expr() << " conver to: " << expr1.get_OperandStack_cp() << endl;

	return 0;
}
