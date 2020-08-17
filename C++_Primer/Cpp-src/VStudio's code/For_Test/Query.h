#ifndef _QUERY_H_
#define _QUERY_H_

//#include<iostream>
//#include<memory>
//#include<string>
#include"TextQuery.h"
#include"Query_base.h"
#include<algorithm>
#include<iterator>

class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&);

    QueryResult eval(const TextQuery& t) const { return q->eval(t); }
    QueryResult eval(const TextQuery& t, size_t lower, size_t upper) const;//[lower,upper]
    std::string rep(void) const;

private:
    Query(const std::shared_ptr<Query_base>& query);
    std::shared_ptr<Query_base> q;
};


extern Query operator~(const Query&);
extern Query operator|(const Query&, const Query&);
extern Query operator&(const Query&, const Query&);
extern std::ostream& operator<<(std::ostream& os, const Query& query);


inline QueryResult
Query::eval(const TextQuery& t, size_t lower, size_t upper) const {
    auto result = eval(t);
    auto new_lines = std::make_shared <TextQuery::lines>();
    std::copy_if(result.begin(), result.end(), std::inserter(*new_lines, new_lines->begin()), 
        [&](size_t n) {return n >= lower-1 && n < upper; });
    return QueryResult(rep(), result.get_file(), new_lines);
}


#endif
