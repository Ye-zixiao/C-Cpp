#include<iostream>
#include<string>
using namespace::std;

string make_plural(size_t ctr, const string& word, const string& ending = "s");

int main(void)
{
	cout << make_plural(2, "failure") << endl;
	cout << make_plural(2, "success") << endl;

	return 0;
}

string make_plural(size_t ctr,const string &word,const string &ending)
{
	return (ctr > 1 && word[word.size() - 1] != 's') ? word+ending :
		(word[word.size() - 1] == 's') ? word + "es" :word;
}
