#ifndef _QUERY_H_
#define _QUERY_H_

#include<iostream>
#include<memory>
#include<string>
#include"TextQuery.h"

class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    //virtual QueryResult eval(const TextQuery&)const = 0;
    virtual std::string rep(void) const = 0;
};

/*
* Query类整合了Query_base整个继承体系的所有类
*/
class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

    friend class NotQuery;
    friend class BinaryQuery;
public:
    Query(const std::string&);

    //QueryResult eval(const TextQuery& t) const { return q->eval(t); }
    std::string rep(void) const {
        std::cout << "Query::rep()" << std::endl;
        return q->rep();
    }

private:
    Query(const std::shared_ptr<Query_base>& query) :q(query) {
        std::cout << "Query(const shared_ptr<Query_base>&)" << std::endl;
    }
    std::shared_ptr<Query_base> q;
};



class WordQuery :public Query_base {
    friend class Query;
private:
    WordQuery(const std::string& s) :query_word(s) {
        std::cout << "WordQuery(const string&)" << std::endl;
    }

    //QueryResult eval(const TextQuery& t) const override { return t.query(query_word); }
    std::string rep(void) const override {
        std::cout << "WordQuery::rep()" << std::endl;
        return query_word;
    }

    std::string query_word;
};

class NotQuery :public Query_base {
    friend Query operator~(const Query&);
private:
    NotQuery(const Query& query) :q(query.q) {
        std::cout << "NotQuery(const Query&)" << std::endl;
    }

    //QueryResult eval(const TextQuery&) const override;
    std::string rep(void) const override {
        std::cout << "NotQuery::rep()" << std::endl;
        return "~(" + q->rep() + ")";
    }

    std::shared_ptr<Query_base> q;
};


class BinaryQuery :public Query_base {
protected:
    BinaryQuery(const Query& l, const Query& r, std::string s) :
        lhs(l.q), rhs(r.q), opSym(s) {
        std::cout << "BinaryQuery(const Query&,const Query&)" << std::endl;
    }

    std::string rep(void) const override{
        std::cout << "BinaryQuery::rep()" << std::endl;
        return "(" + lhs->rep() + " " +
            opSym + " " + rhs->rep() + ")";
    }

    std::shared_ptr<Query_base> lhs,rhs;
    std::string opSym;
};


class AndQuery:public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
private:
    AndQuery(const Query& l, const Query& r) :
        BinaryQuery(l, r, "&") {
        std::cout << "AndQuery(const Query&,const Query&)" << std::endl;
    }

    //QueryResult eval(const TextQuery&) const override;
};

class OrQuery:public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
private:
    OrQuery(const Query& l, const Query& r) :
        BinaryQuery(l, r, "|") {
        std::cout << "OrQuery(const Query&,const Query&)" << std::endl;
    }

    //QueryResult eval(const TextQuery&) const override;
};


extern std::ostream& operator<<(std::ostream&, const Query&);
extern Query operator~(const Query&);
extern Query operator&(const Query&, const Query&);
extern Query operator|(const Query&, const Query&);

#endif
