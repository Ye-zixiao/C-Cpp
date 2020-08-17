#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
using namespace::std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

bool valid(const string&phone)
{
    return phone[0]>='3'?false:true;
}

istream& readtoPeople(istream&is,vector<PersonInfo>& people)
{
    string line,word;
    while(getline(is,line))
    {
        PersonInfo person;
        istringstream record(line);
        record>>person.name;
        while(record>>word)
            person.phones.push_back(word);
        people.push_back(person);
    }
    return is;
}

ostream& printPeople(ostream&os,const vector<PersonInfo> &people)
{
    for(const auto &person:people)
    {
        ostringstream formatted,badnums;
        for(const auto &phone:person.phones)
        {
            if(!valid(phone))
                badnums<<' '<<phone;
            else
                formatted<<' '<<phone;
        }
        if(badnums.str().empty())
            os<<person.name<<' '<<formatted.str()<<endl;
        else
            cerr<<"input error:"<<person.name<<" invalid number(s): "
            <<badnums.str()<<endl;
    }
    return os;
}

int main(void)
{
    ifstream infile("infile.txt");
    if(!infile)
    {
        cerr<<"Error"<<endl;
        return -1;
    }

    vector<PersonInfo> people;
    readtoPeople(infile,people);
    printPeople(cout,people)<<endl;
    infile.close();

    return 0;
}
