#include"Query.h"

/*------------------Query类部分----------------------*/
//inline
Query::Query(const std::string& s) :q(new WordQuery(s)) {
    std::cout << "Query(const string&)" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Query& query) {
    return os << query.rep();
}

/*------------------重载运算符----------------------*/
//inline
Query operator~(const Query& operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

//inline
Query operator&(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

//inline
Query operator|(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
