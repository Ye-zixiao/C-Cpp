#include<iostream>
#include<vector>
#include<string>
#include"Stack.h"

bool Stack::push(const string &my_find)
{
    if(full())
        return false;
    else
    {
        _stack.push_back(my_find);
        return true;
    }
}

bool Stack::pop(string &elem)
{
    if(empty())
        return false;
    else
    {
        elem=_stack.back();
        _stack.pop_back();
        return true;
    }
}

bool Stack::peek(string &elem)
{
    if(empty())
        return false;
    else
    {
        elem=_stack.back();
        return true;
    }
}
