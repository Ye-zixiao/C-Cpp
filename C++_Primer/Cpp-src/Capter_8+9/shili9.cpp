#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace::std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

void print_personinfo(const vector<PersonInfo>&people);

int main(void)
{
    ifstream infile("infile.txt");
    if(infile)
    {
        string line,word;
        vector<PersonInfo> people;
        istringstream record;
        while(getline(infile,line))
        {
            PersonInfo info;
            record.str(line);
            record>>info.name;
            while(record>>word)
                info.phones.push_back(word);
            people.push_back(info);
            record.clear();//因为每一都会读到文件的末尾，触发eofbit置位，故需要复位
        }
        print_personinfo(people);
    }
    else
        cerr<<"Error"<<endl;

    return 0;
}

void print_personinfo(const vector<PersonInfo>&people)
{
    for(const auto&person:people)
    {
        cout<<person.name<<"'s phones:";
        for(const auto &phone:person.phones)
            cout<<phone<<' ';
        cout<<endl;
    }
}
