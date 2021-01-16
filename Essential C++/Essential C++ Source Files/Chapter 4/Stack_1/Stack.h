#ifndef STACK_H_
#define STACK_H_

#include<vector>
#include<string>
using namespace std;

class Stack{
public:
    bool push(const string &);
    bool pop(string &elem);
    bool peek(string &elem);
    bool empty() const { return _stack.empty();}
    bool full() const { return _stack.size()==_stack.max_size(); }
    int size() const { return _stack.size(); };

private:
    vector<string> _stack;
};

#endif // STACK_H_
