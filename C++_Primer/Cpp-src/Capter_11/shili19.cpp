#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<string>
#include<unordered_map>
using namespace::std;

class Test {
	friend size_t hasher(const Test& item);
	friend ostream& operator<<(ostream& os, const Test&);
public:
	Test() = default;
	Test(const string&s,double pri):
		bookname(s),bookprice(pri){}

	bool operator==(const Test& item) const {
		return bookname == item.bookname;
	}

private:
	string bookname;
	double bookprice;
};

size_t hasher(const Test& item)
{
	return hash<string>()(item.bookname);
}

ostream& operator<<(ostream& os, const Test& item)
{
	return os << item.bookname << ' ' << item.bookprice;
}

int main(void)
{
	unordered_map<Test, size_t, size_t (*)(const Test&)> test_map(20,hasher);

	string bookname;
	double price;
	size_t booknumber;
	while (cin >> bookname >> price >> booknumber)
		test_map.insert({ Test(bookname,price),booknumber });

	for (auto citer = test_map.cbegin(); citer != test_map.cend(); ++citer)
		cout << citer->first << citer->second << endl;

	return 0;
}
