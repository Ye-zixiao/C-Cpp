#include"RPN.h"

bool isoperator(char ch)
{
	const std::string compare("+-*/()");
	for (auto character : compare)
		if (character == ch)
			return true;
	return false;
}

int prinum(char ch)
{
	switch (ch)
	{
	case '+':case '-':return 0;
	case '*':case '/':return 1;
	default:std::cerr << "Error"; return -1;
	}
}

int priority(char stacktop, char ch)
{
	int num1 = 0, num2 = 0;
	if ((num1 = prinum(stacktop)) >= 0 && (num2 = prinum(ch)) >= 0)
		return num1 - num2;
	else
	{
		std::cerr << "Error" << std::endl;
		return 100;
	}
}

void RPN::clear_stack(std::stack<std::string>& stk)
{
	while (!stk.empty())
		stk.pop();
}

/*
�沨��ʽ�㷨
  1����������ɨ��һ��׺���ʽ��
   2������ȡ���ǲ����������жϸò����������ͣ������ò����������������ջ
   3������ȡ���������
				   (1) �������Ϊ������"("����ֱ�Ӵ����������ջ��
				   (2) �������Ϊ������")"��������������ջ�е����������������ջ��ֱ������������Ϊֹ����ʱ�����������š�
				   (3) �������Ϊ�������������
					   (a) ���������ջջ���������Ϊ�����ţ���ֱ�Ӵ����������ջ��
					   (b) �����������ջջ������������ȼ��ߣ���ֱ�Ӵ����������ջ��
					   (c) �����������ջջ������������ȼ��ͻ���ȣ������ջ�����������������ջ��ֱ�������ջջ����������ڣ����������ڣ�����������ȼ�,��Ϊ�����ţ�
						   ������ǰ�����ѹ���������ջ��
	4�������ʽ��ȡ��ɺ��������ջ�����������ʱ��������ȡ�����������������ջ��ֱ���������ջΪ�ա�

	ͼʾ��
	=  =							=  =	���ȼ��ߵ������������
	=  =							=  =
	=  =							=  =
	=  =							=  =	���ȼ��͵������������
	====							====
������ջOperandStack			�����ջOperatorStack
*/
void RPN::suffix_expr(const std::string& expr)
{
	for (std::string::size_type pos=0;pos<expr.size();++pos)
	{
		if (!isoperator(expr[pos]))					//��ò�����
		{
			std::string temp = std::to_string(stoi(expr.substr(expr.find_first_of("0123456789", pos))));
			OperandStack.push(temp);
			pos = expr.find_first_not_of("0123456789", pos);
			/*��pos�������һ�������ַ�ʱ��������ҷ������ַ����������ܴ��λ�ã���������Խ����Ϊ��
			������find��������string���һ��п��ܻ��ҳ�������ģ��������ж�ʱ�����pos<expr.size()��Ϊ�ж�������*/
			--pos;
		}
		else
		{
			switch (expr[pos])
			{
			case '(':
				OperatorStack.push(std::string(1, expr[pos]));//����ȡ���ֵ�ʱ�����ﻹ�����޸��£���Ϊ����ֻ����ȡһ���ַ�
													//�������ʹ���±����õķ�ʽ�������ʹ��find_first_of(���ֵ��������ֵĲ���)��
				break;
			case ')':
				while (OperatorStack.top().front() != '(')
				{
					OperandStack.push(OperatorStack.top());
					OperatorStack.pop();
				}
				OperatorStack.pop();
				break;
			default://����������*-+/
				if (OperatorStack.empty() ||
					OperatorStack.top().front() == '(' || priority(OperatorStack.top().front(), expr[pos]) < 0)
					OperatorStack.push(std::string(1, expr[pos]));
				else
				{
					while (!OperatorStack.empty() &&
						OperatorStack.top().front() != '(' && priority(OperatorStack.top().front(), expr[pos]) >= 0)
					{
						std::string temp = OperatorStack.top();
						OperandStack.push(temp);
						OperatorStack.pop();
					}
					OperatorStack.push(std::string(1, expr[pos]));
				}
				break;
			}
		}
	}
	while (!OperatorStack.empty())
	{
		OperandStack.push(OperatorStack.top());
		OperatorStack.pop();
	}
}

std::ostream& reverse_print(std::stack<std::string>& stk, std::ostream& os)
{
	std::string temp = stk.top();
	stk.pop();
	if (!stk.empty())
		reverse_print(stk, os);
	return os << temp << ' ';
}


std::ostream& operator<<(std::ostream& os, std::stack<std::string> stk)
{
	if (stk.empty())
		return os;
	return reverse_print(stk, os);
}
