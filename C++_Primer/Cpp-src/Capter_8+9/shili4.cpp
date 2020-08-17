#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace::std;

bool read_line(vector<string>& store,const string &file_name)
{
    ifstream in(file_name);
    string temp;
    if(!in)
    {
        cerr<<"Can't open this file!"<<endl;
        return false;
    }
    while(getline(in,temp))
        store.push_back(temp);
    return true;
}

bool read_word(vector<string>&store,const string&file_name)
{
    ifstream in(file_name);
    string temp;
    if(!in)
    {
        cerr<<"Can't open this file!"<<endl;
        return false;
    }
    while(in>>temp)
        store.push_back(temp);
    return true;
}

bool read(vector<string>& svec,const string&file_name)
{
    ifstream in(file_name);
    if(in)
    {
        string temp;
        while(getline(in,temp))
            svec.push_back(temp);
        return true;
    }
    return false;
}

ostream& print(const vector<string>&store,ostream&os=cout)
{
    for(const auto&elem:store)
        os<<elem<<endl;
    return os;
}

int main(int argc,char *argv[])
{
    vector<string> svec;
    const string filename(argv[1]);
    if(read_line(svec,filename))
        print(svec)<<endl;
    else
        cerr<<"Some error have happened!"<<endl;

    vector<string> svec1;
    if(read_word(svec1,filename))
        print(svec1)<<endl;
    else
        cerr<<"Some error have happened!"<<endl;

    vector<string> svec_2;
    if(read(svec_2,filename))
        print(svec_2)<<endl;
    else
        cerr<<"No data?"<<endl;

    return 0;
}
