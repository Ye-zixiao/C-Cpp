#ifndef _DERIVED_QUERY_
#define _DERIVED_QUERY_

//Query.h已经包含了Query_base.h这个头文件，因为Query类定义中包含了指向Query_base的共享指针实体
#include"Query.h"
#include<algorithm>
#include<iterator>


class WordQuery :public Query_base {
    friend class Query;
private:
    WordQuery(const std::string& s);

    QueryResult eval(const TextQuery& t) const override { return t.query(query_word); }
    std::string rep(void) const override;

    std::string query_word;
};

class NotQuery :public Query_base {
    friend Query operator~(const Query&);
private:
    NotQuery(const Query& q);

    QueryResult eval(const TextQuery&) const override;
    std::string rep(void) const override;

    Query query;
};


class BinaryQuery :public Query_base {
protected:
    BinaryQuery(const Query& l, const Query& r, std::string s);

    std::string rep(void) const override;

    Query lhs, rhs;
    std::string opSym;
};


class AndQuery :public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
private:
    AndQuery(const Query& l, const Query& r);

    QueryResult eval(const TextQuery&) const override;
};

class OrQuery :public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
private:
    OrQuery(const Query& l, const Query& r);

    QueryResult eval(const TextQuery&) const override;
};


#endif