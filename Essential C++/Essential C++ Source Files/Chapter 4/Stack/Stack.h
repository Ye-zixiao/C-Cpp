#pragma once
#include<vector>
#include<string>
using namespace std;

class Stack
{
public:
	bool push(const string& elem);
	bool pop(string& elem);
	bool last_one(string& elem);			//�������һ��Ԫ�ص����ݣ���ջ��Ԫ�أ�

	bool find(const string& elem) const;
	int count(const string& elem) const;

	bool empty() { return _stack.empty(); }
	bool full() { return _stack.size() == _stack.max_size(); }

	int size() { return _stack.size(); }

private:
	vector<string> _stack;
};
