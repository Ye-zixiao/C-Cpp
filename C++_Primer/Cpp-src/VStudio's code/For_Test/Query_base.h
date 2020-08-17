#ifndef _QUERY_BASE_H_
#define _QUERY_BASE_H_
//#define DEBUG//���Ԥ���������Ƿ��ӡ������Ĺ��캯����һЩ��������Ĺ���

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