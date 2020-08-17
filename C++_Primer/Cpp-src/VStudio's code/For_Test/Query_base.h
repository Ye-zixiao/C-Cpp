#ifndef _QUERY_BASE_H_
#define _QUERY_BASE_H_
//#define DEBUG//这个预处理宏决定是否打印派生类的构造函数和一些函数处理的过程

#include<iostream>
#include<string>
#include<memory>
#include<algorithm>
#include"TextQuery.h"

class Query_base {
    friend class Query;
protected:
    using lines = TextQuery::lines;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery&)const = 0;
    virtual std::string rep(void) const = 0;
};


#endif