#include<iostream>
#include<stack>
#include<string>
#define NDEBUG//要在RPN.h前面定义才有效
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
