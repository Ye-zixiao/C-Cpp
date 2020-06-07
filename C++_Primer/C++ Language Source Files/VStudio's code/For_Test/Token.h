#ifndef _TOKEN_H_
#define _TOKEN_H_

#include<string>
#include<iostream>
#include<utility>
#include"Sales_data.h"


class Token {
	friend std::ostream& operator<<(std::ostream&, const Token&);
public:
	Token():tok(INT),ivalue(0){}
	Token(const Token& t) :tok(t.tok) { copyUnion(t); }
	Token(Token&& t) noexcept:tok(t.tok) { moveUnion(std::forward<Token>(t)); }
	~Token() { 
		if (STR == tok)str.~basic_string();
		else if (SD == tok)sd.~Sales_data();
	}

	Token& operator=(const Token&);
	Token& operator=(Token&&)noexcept;
	Token& operator=(const std::string&);
	Token& operator=(const Sales_data&);
	Token& operator=(char);
	Token& operator=(int);
	Token& operator=(double);

private:
	enum {INT,CHAR,DOUBLE,STR,SD} tok;
	union {
		int ivalue;
		char chvalue;
		double dvalue;
		std::string str;
		Sales_data sd;
	};
	void copyUnion(const Token&);
	void moveUnion(Token&&)noexcept;
};

void Token::copyUnion(const Token&t) {
	switch (t.tok) {
		case INT:ivalue = t.ivalue; break;
		case DOUBLE:dvalue = t.dvalue; break;
		case CHAR:chvalue = t.chvalue; break;
		case SD:new (&sd) Sales_data(t.sd); break;
		case STR:new (&str) std::string(t.str); break;
	}
}

void Token::moveUnion(Token&& t)noexcept {
	switch (t.tok) {
	case INT:ivalue = t.ivalue; t.ivalue = 0; break;
	case CHAR:chvalue = t.chvalue; t.chvalue = '\0'; break;
	case DOUBLE:dvalue = t.dvalue; t.dvalue = 0.0; break;
	case SD:new (&sd) Sales_data(std::move(t.sd)); break;
	case STR:new (&str) std::string(std::move(t.str)); break;
	}
}

Token& Token::operator=(const Token& t) {
	if (tok == STR && t.tok != STR)str.~basic_string();
	if (tok == SD && t.tok != SD)sd.~Sales_data();
	if (tok == STR && t.tok == STR)str = t.str;
	else if (tok == SD && t.tok == SD)sd = t.sd;
	else copyUnion(t);
	tok = t.tok;
	return *this;
}

Token& Token::operator=(Token&& t) noexcept {
	if (tok == STR && t.tok != STR)str.~basic_string();
	if (tok == SD && t.tok != SD)sd.~Sales_data();
	if (tok == STR && t.tok == STR)str = std::move(t.str);
	else if (tok == SD && t.tok == SD) sd = std::move(t.sd);
	else moveUnion(std::forward<Token>(t));
	tok = t.tok;
	return *this;
}

Token& Token::operator=(const std::string&s) {
	if (STR == tok)str = std::move(s);
	if (SD == tok)sd.~Sales_data();
	new (&str) std::string(s);
	tok = STR;
	return *this;
}

Token& Token::operator=(const Sales_data& s) {
	if (SD == tok)sd = std::move(s);
	if (STR == tok)str.~basic_string();
	new (&sd) Sales_data(s);
	tok = SD;
	return *this;
}

Token& Token::operator=(int v) {
	if (STR == tok)str.~basic_string();
	else if (SD == tok)sd.~Sales_data();
	ivalue = v;
	tok = INT;
	return *this;
}

Token& Token::operator=(double d) {
	if (STR == tok)str.~basic_string();
	else if (SD == tok)sd.~Sales_data();
	dvalue = d;
	tok = DOUBLE;
	return *this;
}

Token& Token::operator=(char ch) {
	if (STR == tok)str.~basic_string();
	else if (SD == tok)sd.~Sales_data();
	chvalue = ch;
	tok = CHAR;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Token& t) {
	switch (t.tok) {
	case Token::CHAR:os << t.chvalue; break;
	case Token::INT:os << t.ivalue; break;
	case Token::DOUBLE:os << t.dvalue; break;
	case Token::SD:os << t.sd; break;
	case Token::STR:os << t.str; break;
	}
	return os;
}

#endif