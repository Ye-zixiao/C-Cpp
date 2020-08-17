#ifndef _TUPLE_TEXTQUERY_H_
#define _TUPLE_TEXTQUERY_H_

//#define DEBUG
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<tuple>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>

class tupleTextQuery {
public:
    using size_type = std::vector<std::string>::size_type;
    using lines_set = std::set<size_type>;
    using lines_set_sp = std::shared_ptr<lines_set>;
    using text = std::vector<std::string>;
    using text_sp = std::shared_ptr<text>;
    using Query_Result = std::tuple<std::string, text_sp, lines_set_sp>;

    tupleTextQuery(std::ifstream& ifs) :
        ptext(new std::vector<std::string>()) {
        input(ifs);
    }

    Query_Result query(const std::string& str);

private:
    void input(std::ifstream& ifs);
    std::shared_ptr<std::vector<std::string>> ptext;
    std::unordered_map<std::string, std::shared_ptr<lines_set>> word_lines;
};


void tupleTextQuery::input(std::ifstream& ifs) {
    size_type cnt = 0;
    for (std::string line; getline(ifs, line); ++cnt) {
#ifdef DEBUG
        std::cout << line << std::endl;
#endif
        ptext->push_back(line);
        std::istringstream istring(line);
        for (std::string word; istring >> word;) {
            auto& ret = word_lines[word];
            if (!ret)
                ret.reset(new lines_set());
            ret->insert(cnt);
        }
    }
}

tupleTextQuery::Query_Result
tupleTextQuery::query(const std::string& str) {
    static std::shared_ptr<lines_set> nullsetp(new lines_set());
    auto ret = word_lines.find(str);
    if (ret != word_lines.end())
        return { str,ptext,ret->second };
    else
        return { str,ptext,nullsetp };
}


std::ostream& operator<<(std::ostream& os, const tupleTextQuery::Query_Result& item) {
    os << "String " << get<0>(item) << " occurs " << get<2>(item)->size() << " times:" << std::endl;
    auto ptext = get<1>(item);
    for (const auto& line_no : *get<2>(item)) {
        os << "\t|___ (line " << line_no + 1 << "): " << (*ptext)[line_no] << std::endl;
    }
    return os;
}

#endif
