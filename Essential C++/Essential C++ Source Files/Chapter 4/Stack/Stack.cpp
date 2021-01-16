#include<string>
#include<vector>
#include<algorithm>
#include"Stack.h"

bool Stack::push(const string& elem)
{
	if (full())
		return false;
	else
	{
		_stack.push_back(elem);
		return true;
	}
}

bool Stack::pop(string& elem)
{
	if (empty())
		return false;
	else
	{
		elem = _stack.back();
		_stack.pop_back();		//pop_back函数是不会返回删除的值的
		return true;
	}
}

bool Stack::last_one(string& elem)
{
	if (empty())
		return false;
	else
	{
		elem = _stack.back();
		return true;
	}
}

bool Stack::find(const string& elem) const
{
	/*需要理解的是STL中的find算法当找到相应的数据时返回的是容器中间某个位置的迭代器
	，而当找不到的时候它会返回容器最后一个元素下一个位置的迭代器*/
	return ::find(_stack.begin(), _stack.end(), elem) != _stack.end();
}
int Stack::count(const string& elem) const
{
	return ::count(_stack.begin(), _stack.end(), elem);
}
