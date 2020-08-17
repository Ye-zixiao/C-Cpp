#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace::std;

int main(void)
{
	multimap<string, string> author_books{
		{"Tom","Fly with me"},{"Hanks","Show me the code"},
		{"Tom","Do your favor"},{"Jimmy","Talk is cheap"},
		{"Hanks","Just so so"}
	};
	for (const auto& pair : author_books)
		cout << pair.first << ": " << pair.second << endl;
	cout << "=======================" << endl << endl;

	for (auto ret_pair = author_books.equal_range("Hanks"); ret_pair.first != ret_pair.second;)
		ret_pair.first = author_books.erase(ret_pair.first);

	for (const auto& pair : author_books)
		cout << pair.first << ": " << pair.second << endl;

	return 0;
}
