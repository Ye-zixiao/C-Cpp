#include"Query.h"
#include"Query_derived.h"

std::string
Query::rep(void) const {
#ifdef DEBUG
    std::cout << "Query::rep()" << std::endl;
#endif
    return q->rep();
}

Query::Query(const std::shared_ptr<Query_base>& query) :q(query) {
#ifdef DEBUG
    std::cout << "Query(const shared_ptr<Query_base>&)" << std::endl;
#endif
}

Query::Query(const std::string& s) : q(new WordQuery(s)) {
#ifdef DEBUG
    std::cout << "Query(const string&)" << std::endl;
#endif
}

Query operator~(const Query& operand) {

    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

Query operator&(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

Query operator|(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

std::ostream& operator<<(std::ostream& os, const Query& query) {
    return os << query.rep();
}