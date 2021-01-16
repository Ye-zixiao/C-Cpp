#include<set>
#include<string>
#include<iostream>
#include"TextQuery.h"
using namespace::std;


int main(void)
{
	ifstream infile;
	TextQuery file_database;

	string word;
	do{
        cout << "Enter the word your want to search('quit' to quit) $:";
		cin >> word;
		switch (word[0])
		{
		case('\\'):
			try{
                    openfile(infile, word.substr(1));
                    file_database.reset(infile, word.substr(1));
            }
            catch(runtime_error&err){
                cerr<<err.what()<<endl;
            }
            continue;
		case('-'):
			cout << file_database.text();
			continue;
		case('/'):
			cout << file_database.query(word.substr(1));
		default:
			break;
		}
	}
	while(word!="quit");
	cout << "----->quit<-----" << endl;

	return 0;
}
