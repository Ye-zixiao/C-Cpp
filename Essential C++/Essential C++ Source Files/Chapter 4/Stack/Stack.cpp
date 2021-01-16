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
		_stack.pop_back();		//pop_back�����ǲ��᷵��ɾ����ֵ��
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
	/*��Ҫ������STL�е�find�㷨���ҵ���Ӧ������ʱ���ص��������м�ĳ��λ�õĵ�����
	�������Ҳ�����ʱ�����᷵���������һ��Ԫ����һ��λ�õĵ�����*/
	return ::find(_stack.begin(), _stack.end(), elem) != _stack.end();
}
int Stack::count(const string& elem) const
{
	return ::count(_stack.begin(), _stack.end(), elem);
}
