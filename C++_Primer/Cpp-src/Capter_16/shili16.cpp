#include<iostream>
#include<string>
#include<utility>
#include<memory>
#include<vector>
using namespace::std;

class Book {
public:
	Book(const string&str,double pri):
		bookname(str),price(pri){}
	Book():
		bookname(string()),price(0){}

	pair<string, double> get(void)const {
		return { bookname,price };
	}

private:
	string bookname;
	double price;
};

class BookVec {
public:
	BookVec():
		pbookvec(new vector<Book>()){}

	template<typename... Args>
	void emplace_back(const Args&... args) {
		pbookvec->push_back(Book(args...));
	}
	size_t size(void) const {
		return pbookvec->size();
	}

private:
	shared_ptr<vector<Book>> pbookvec;
};

int main(void)
{
	BookVec item;
	item.emplace_back("hello world", 23.2);
	item.emplace_back();
	item.emplace_back("show", 22.2);
	cout << item.size() << endl;
	return 0;
}
