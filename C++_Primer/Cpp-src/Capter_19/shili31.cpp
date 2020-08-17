#include<iostream>
#include<string>
#include<utility>
using namespace::std;

class Token {
	friend ostream& operator<<(ostream& os, const Token& t);
public:
	Token():tok(INT),ivar(0){}
	Token(const Token& t) :tok(t.tok) { copyUnion(t); }
	Token(Token&&t) :tok(std::move(t.tok)) { moveUnion(std::forward<Token>(t)); }
	Token& operator=(const Token& t);
	Token& operator=(Token&&)noexcept;
	~Token() {
		if (tok == STR)strvar.~basic_string();
	}

	Token& operator=(const string&);
	Token& operator=(int);
	Token& operator=(char);
	Token& operator=(double);
private:
	enum { INT, CHAR, DBL, STR } tok;
	union {
		char cvar;
		int ivar;
		double dvar;
		string strvar;
	};
	void copyUnion(const Token&);
	void moveUnion(Token&&);
};

void Token::copyUnion(const Token& t) {
	switch (t.tok) {
		case STR:new (&strvar) string(t.strvar); break;
		case INT:ivar = t.ivar; break;
		case CHAR:cvar = t.cvar; break;
		case DBL:dvar = t.dvar; break;
	}
}

void Token::moveUnion(Token&& t) {
	switch (t.tok) {
	case STR:new (&strvar) string(std::move(t.strvar)); break;
	case INT:ivar = std::move(t.ivar); t.ivar = 0; break;
	case CHAR:cvar = std::move(t.cvar); t.cvar = '\0'; break;
	case DBL:dvar = std::move(t.dvar); t.dvar = 0.0; break;
	}
}

Token& Token::operator=(const Token& t) {
	if (tok == STR && STR != t.tok)strvar.~basic_string();
	if (STR == tok && STR == t.tok)strvar = t.strvar;
	else copyUnion(t);
	tok = t.tok;
	return *this;
}

Token& Token::operator=(Token&& t)noexcept {
	if (STR == tok && t.tok != STR)strvar.~basic_string();
	if (STR == tok && STR == t.tok)strvar = std::move(t.strvar);
	else moveUnion(std::forward<Token>(t));
	return *this;
}

Token& Token::operator=(const string& str) {
	if (tok == STR)strvar = str;
	else {
		new (&strvar) string(str);
		tok = STR;
	}
	return *this;
}

Token& Token::operator=(char c) {
	if (STR == tok)strvar.~basic_string();
	cvar = c; tok = CHAR;
	return *this;
}

Token& Token::operator=(int i) {
	if (STR == tok)strvar.~basic_string();
	ivar = i; tok = INT;
	return*this;
}

Token& Token::operator=(double d) {
	if (STR == tok)strvar.~basic_string();
	dvar = d; tok = DBL;
	return *this;
}

ostream& operator<<(ostream& os, const Token& t) {
	switch (t.tok) {
	case Token::INT:os << t.ivar; break;
	case Token::CHAR:os << t.cvar; break;
	case Token::DBL:os << t.dvar; break;
	case Token::STR:os << t.strvar; break;
	}
	return os;
}

int main(void)
{
	Token item;
	cout << item << endl;
	item = string("hello world");
	cout << item << endl;
	item = item;
	cout << item << endl;
	item = std::move(item);
	cout << item << endl;

	Token item_mv = std::move(item);
	cout << "old item: " << item << endl
		<< "new item_mv: " << item_mv << endl;

	item = 12; cout << item << endl;
	item = 12.1; cout << item << endl;
	item = 'd'; cout << item << endl;
	item = string("china baby"); cout << item << endl;

	Token _char_item; _char_item = 'c';
	Token _char_item_mv = std::move(_char_item);
	cout << "old char: " << _char_item << "|"<<endl
		<< "new char: " << _char_item_mv << endl;

	return 0;
}
