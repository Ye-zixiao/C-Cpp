#ifndef LIKE_TEXTQUERY_H_INCLUDED
#define LIKE_TEXTQUERY_H_INCLUDED

#include"StrVec.h"
#include<unordered_map>
#include<set>
#include<fstream>
#include<iostream>
#include<sstream>

/*虽然在同一个项目中不同的类定义在不同的头文件中，但即使如此，也不要在同一个文件中
*定义两个拥有相同名字的类，这会导致编译器提示“符号名字重定义错误”
*/
class like_QueryResult;

class like_TextQuery {
public:
    using line_no = StrVec::size_type;
    using lines = std::set<line_no>;

    like_TextQuery(std::ifstream& is) :
        pfile(new StrVec) {
        input(is);
    }

    like_QueryResult query(const std::string& str);

private:
    void input(std::ifstream& is);
    std::shared_ptr<StrVec> pfile;
    std::unordered_map<std::string, std::shared_ptr<lines>> pword_lines;
};


class like_QueryResult {
    friend std::ostream& operator<<(std::ostream& os, const like_QueryResult& item);
public:
    using line_no = StrVec::size_type;
    using lines = std::set<line_no>;
    like_QueryResult(const std::string& str, std::shared_ptr<StrVec> pf, std::shared_ptr<lines> pl) :
        word(str), pfile(pf), plines(pl) {}

private:
    std::string word;
    std::shared_ptr<StrVec> pfile;
    std::shared_ptr<lines> plines;
};


/*---------------------------相关类成员函数定义----------------------------------------*/

void
like_TextQuery::input(std::ifstream& is) {
    line_no cnt = 0;
    for (std::string line; getline(is, line); ++cnt) {
        pfile->push_back(line);
        std::istringstream line_stream(line);
        for (std::string word; line_stream >> word;) {
            auto& ret = pword_lines[word];
            if (!ret)
                //ret.reset(new lines);//要让一个shared_ptr共享指针指向新的动态内存，尽量使用reset函数
                //不过要知道共享指针：q.reset(p1)与q=p2具有一定的等价性，不同之处在于p1是内置指针，p2是共享指针
                ret = std::make_shared<lines>();
            ret->insert(cnt);
        }
    }
}

like_QueryResult
like_TextQuery::query(const std::string& str) {
    static std::shared_ptr<lines> nullset(new lines);
    auto iter = pword_lines.find(str);
    if (iter != pword_lines.end())
        return like_QueryResult(str, pfile, iter->second);
    else
        return like_QueryResult(str, pfile, nullset);
}

std::ostream& operator<<(std::ostream& os, const like_QueryResult& item) {
    os << item.word << " occurs " << item.plines->size() << " times:" << std::endl;
    for (const auto& elem : *item.plines)
        os << "\t|___lines(" << elem << "): " << (*item.pfile)[elem] << std::endl;
    return os;
}

#endif // LIKE_TEXTQUERY_H_INCLUDED
