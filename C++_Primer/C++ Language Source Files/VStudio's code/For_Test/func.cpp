#include<iostream>
#include<string>
#include"Sales_data.h"
#include"StrBlob.h"
#include"TextQuery.h"

std::istream& operator>>(std::istream&is,Sales_data&item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream& operator<<(std::ostream&os,const Sales_data&item)
{
	return os << '\t' << item.bookNo << ' ' << item.units_sold << ' ' << item.revenue << ' ' << item.avg_price();
}

Sales_data& Sales_data::combine(const Sales_data& item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

const Sales_data& Sales_data::operator=(const Sales_data& item)
{
	bookNo = item.bookNo;
	units_sold = item.units_sold;
	revenue = item.revenue;
	return *this;
}

bool isShorter_Isbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn() ? true : false;
}

Sales_data& operator+(Sales_data&add,const Sales_data& item)
{
	add.units_sold += item.units_sold;
	add.revenue += item.revenue;
	return add;
}

/*
*StrBlob类：保存一个共享的由动态内存分配出的vector<string>
*/

StrBlob::StrBlob_ptr StrBlob::begin(void)
{
	return StrBlob_ptr(*this);
}

StrBlob::StrBlob_ptr StrBlob::end(void)
{
	return StrBlob_ptr(*this, pstrvec->size());
}

StrBlob::cStrBlob_ptr StrBlob::cbegin(void) const
{
	return cStrBlob_ptr(*this);
}

StrBlob::cStrBlob_ptr StrBlob::cend(void) const
{
	return cStrBlob_ptr(*this, pstrvec->size());
}


std::ostream& operator<<(std::ostream& os, const StrBlob& item)
{
	for (const auto& elem : *item.pstrvec)
		os << elem << ' ';
	return os;
}

/*
*TextQuery类的成员函数
*
*/

void TextQuery::input(std::ifstream& is)
{
	line_no cnt = 0;
	for (std::string line; getline(is, line);++cnt)
	{
		pfile->push_back(line);
		std::istringstream line_stream(line);
		for (std::string word; line_stream >> word;) {
			auto& line_no_set = this->word_lines[word];
			if (!line_no_set)
				line_no_set.reset(new lines());
			line_no_set->insert(cnt);
		}
	}
}

QueryResult TextQuery::query(const std::string& str) const
{
	static std::shared_ptr<lines> nullset(new lines);
	//必须创建一个动态对象new set<size_t>，这样我们解引用*item.pline_set时不会出错（因为我们不能解引用空指针）
	auto iter = this->word_lines.find(str);
	if (iter != word_lines.end())
		return QueryResult(str, this->pfile, iter->second);
	else
		return QueryResult(str, pfile, nullset);
}

std::ostream& operator<<(std::ostream& os, const QueryResult& item)
{
	os << item.word << " occurs " << item.pline_set->size() << std::endl;
	for (const auto& line_No : *item.pline_set)
		os << "\t|___line(" << line_No + 1 << ")  " << (*item.pfile)[line_No] << std::endl;
	return os;
}