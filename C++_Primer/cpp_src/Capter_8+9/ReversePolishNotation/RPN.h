#ifndef RPN_H_INCLUDED
#define RPN_H_INCLUDED

#include <iostream>
#include <string>
#include <stack>

/*
*类名：RPN
*作用：接收一个数学表达式，计算出其后缀表达式，将其存放在一个操作数栈中
*提供接口：set_expr_str()接受一个新表达式，计算出最新的后缀表达式，然后存放在栈中
*          get_OperandStack_cp()无参，返回类对象中最新的操作数栈的副本
*          get_expr()无参，返回最新的中缀表达式
*          result()无参，返回表达式的最终数学计算结果
*/
class RPN {
public:
	RPN() = default;
	RPN(const std::string& expr_str):expr(expr_str) { suffix_expr(expr_str); }

	const RPN& set_expr_str(const std::string& expr_str);
	std::stack<std::string> get_OperandStack_cp(void)const { return OperandStack; }	//返回调用者类对象的操作数栈的副本
	std::string get_expr(void) const { return this->expr; }
	int result(void)const;//计算后缀表达式的最终计算结果
private:
	void clear_stack(std::stack<std::string>&stk);
	void suffix_expr(const std::string& expr);//计算后缀表达式
	std::string expr;
	std::stack<std::string> OperandStack, OperatorStack;
};


inline const RPN& RPN::set_expr_str(const std::string&expr_str)//提供一个新的表达式字符串，返回const的this类对象
{
    expr=expr_str;
    clear_stack(OperandStack);
#ifndef NDEBUG
		if (OperandStack.empty())
			std::cout << "empty operandstack" << std::endl;
#endif
		suffix_expr(expr_str);
		return *this;
}

bool isoperator(char ch);
int prinum(char ch);
int priority(char stacktop, char ch);
std::ostream& reverse_print(std::stack<std::string>& stk, std::ostream& os);
std::ostream& operator<<(std::ostream& os, std::stack<std::string> stk);

#endif // RPN_H_INCLUDED
