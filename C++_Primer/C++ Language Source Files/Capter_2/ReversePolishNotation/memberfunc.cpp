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
逆波兰式算法
  1、从左至右扫描一中缀表达式。
   2、若读取的是操作数，则判断该操作数的类型，并将该操作数存入操作数堆栈
   3、若读取的是运算符
				   (1) 该运算符为左括号"("，则直接存入运算符堆栈。
				   (2) 该运算符为右括号")"，则输出运算符堆栈中的运算符到操作数堆栈，直到遇到左括号为止，此时抛弃该左括号。
				   (3) 该运算符为非括号运算符：
					   (a) 若运算符堆栈栈顶的运算符为左括号，则直接存入运算符堆栈。
					   (b) 若比运算符堆栈栈顶的运算符优先级高，则直接存入运算符堆栈。
					   (c) 若比运算符堆栈栈顶的运算符优先级低或相等，则输出栈顶运算符到操作数堆栈，直至运算符栈栈顶运算符低于（不包括等于）该运算符优先级,或为左括号，
						   并将当前运算符压入运算符堆栈。
	4、当表达式读取完成后运算符堆栈中尚有运算符时，则依序取出运算符到操作数堆栈，直到运算符堆栈为空。

	图示：
	=  =							=  =	优先级高的运算符在上面
	=  =							=  =
	=  =							=  =
	=  =							=  =	优先级低的运算符在下面
	====							====
操作数栈OperandStack			运算符栈OperatorStack
*/
void RPN::suffix_expr(const std::string& expr)
{
	for (std::string::size_type pos=0;pos<expr.size();++pos)
	{
		if (!isoperator(expr[pos]))					//获得操作数
		{
			std::string temp = std::to_string(stoi(expr.substr(expr.find_first_of("0123456789", pos))));
			OperandStack.push(temp);
			pos = expr.find_first_not_of("0123456789", pos);
			/*当pos处在最后一个数字字符时向后面再找非数字字符会跳出到很大的位置，即发生了越界行为，
			（可能find不仅会在string内找还有可能会找出在外面的，所以在判断时最好让pos<expr.size()作为判断条件）*/
			--pos;
		}
		else
		{
			switch (expr[pos])
			{
			case '(':
				OperatorStack.push(std::string(1, expr[pos]));//在提取数字的时候这里还可以修改下，因为这里只会提取一个字符
													//比如可以使用下标引用的方式来解决（使用find_first_of(数字到不是数字的部分)）
				break;
			case ')':
				while (OperatorStack.top().front() != '(')
				{
					OperandStack.push(OperatorStack.top());
					OperatorStack.pop();
				}
				OperatorStack.pop();
				break;
			default://获得运算符：*-+/
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
