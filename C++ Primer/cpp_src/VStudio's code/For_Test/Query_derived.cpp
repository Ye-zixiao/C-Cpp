#include"Query_derived.h"

WordQuery::WordQuery(const std::string& s) :query_word(s) {
#ifdef DEBUG
    std::cout << "WordQuery(const string&)" << std::endl;
#endif
}

std::string
WordQuery::rep(void) const {
#ifdef DEBUG
    std::cout << "WordQuery::rep()" << std::endl;
#endif
    return query_word;
}

NotQuery::NotQuery(const Query& q) :query(q) {
#ifdef DEBUG
    std::cout << "NotQuery(const Query&)" << std::endl;
#endif
}

std::string
NotQuery::rep(void) const {
#ifdef DEBUG
    std::cout << "NotQuery::rep()" << std::endl;
#endif
    return "~(" + query.rep() + ")";
}

BinaryQuery::BinaryQuery(const Query& l, const Query& r, std::string s) :
    lhs(l), rhs(r), opSym(s) {
#ifdef DEBUG
    std::cout << "BinaryQuery(const Query&,const Query&)" << std::endl;
#endif
}

std::string
BinaryQuery::rep(void) const {
#ifdef DEBUG
    std::cout << "BinaryQuery::rep()" << std::endl;
#endif
    return "(" + lhs.rep() + " " +
        opSym + " " + rhs.rep() + ")";
}

AndQuery::AndQuery(const Query& l, const Query& r) :
    BinaryQuery(l, r, "&") {
#ifdef DEBUG
    std::cout << "AndQuery(const Query&,const Query&)" << std::endl;
#endif
}

OrQuery::OrQuery(const Query& l, const Query& r) :
    BinaryQuery(l, r, "|") {
#ifdef DEBUG
    std::cout << "OrQuery(const Query&,const Query&)" << std::endl;
#endif
}


/*---------------------------------------------------------------------------*/
QueryResult
OrQuery::eval(const TextQuery& text) const {
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto new_lines = std::make_shared<lines>(left.begin(), left.end());
    new_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), right.get_file(), new_lines);
}

QueryResult
AndQuery::eval(const TextQuery& text) const {
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto new_lines = std::make_shared<lines>();
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*new_lines,new_lines->begin()));
    return QueryResult(rep(), right.get_file(), new_lines);
}

QueryResult
NotQuery::eval(const TextQuery& text) const {
    auto result = query.eval(text);
    auto new_lines = std::make_shared<lines>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t i = 0; i < sz; ++i) {
        if (i != *beg || beg == end)
            new_lines->insert(i);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), result.get_file(), new_lines);
}