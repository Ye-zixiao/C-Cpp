#include<iostream>
#include<string>
#include<fstream>
#include"TextQuery.h"
using namespace::std;

int main(void)
{
	ifstream infile("infile.txt", ifstream::in);
	if (!infile) {
		cerr << "Can't open this file" << endl;
		return -1;
	}
	TextQuery text(infile);

	do {
		string word;
		cout << "Enter a word to search(quit to quit):";
		if (!(cin >> word) || word == "quit")
			break;
		auto item = text.query(word);//构造查询结果类对象
		cout << item << endl;
		/*for (auto iter = item.begin(); iter != item.end(); ++iter)cout << *iter << ' '; cout << endl;*/
	} while (true);
	cout << "---->quit<-----" << endl;

	return 0;
}
