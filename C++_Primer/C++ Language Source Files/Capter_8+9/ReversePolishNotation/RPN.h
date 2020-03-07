#ifndef RPN_H_INCLUDED
#define RPN_H_INCLUDED

#include <iostream>
#include <string>
#include <stack>

/*
*������RPN
*���ã�����һ����ѧ���ʽ����������׺���ʽ����������һ��������ջ��
*�ṩ�ӿڣ�set_expr_str()����һ���±��ʽ����������µĺ�׺���ʽ��Ȼ������ջ��
*          get_OperandStack_cp()�޲Σ���������������µĲ�����ջ�ĸ���
*          get_expr()�޲Σ��������µ���׺���ʽ
*          result()�޲Σ����ر��ʽ��������ѧ������
*/
class RPN {
public:
	RPN() = default;
	RPN(const std::string& expr_str):expr(expr_str) { suffix_expr(expr_str); }

	const RPN& set_expr_str(const std::string& expr_str);
	std::stack<std::string> get_OperandStack_cp(void)const { return OperandStack; }	//���ص����������Ĳ�����ջ�ĸ���
	std::string get_expr(void) const { return this->expr; }
	int result(void)const;//�����׺���ʽ�����ռ�����
private:
	void clear_stack(std::stack<std::string>&stk);
	void suffix_expr(const std::string& expr);//�����׺���ʽ
	std::string expr;
	std::stack<std::string> OperandStack, OperatorStack;
};


inline const RPN& RPN::set_expr_str(const std::string&expr_str)//�ṩһ���µı��ʽ�ַ���������const��this�����
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
