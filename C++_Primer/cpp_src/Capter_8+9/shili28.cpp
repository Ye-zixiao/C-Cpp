#include<string>
#include<iostream>
using namespace::std;

string replace_func(string &s,const string&oldVal,const string &newVal)
{
    auto curr=s.begin();
    while(curr!=s.end()-oldVal.size())
    {
        if(oldVal==string(curr,curr+oldVal.size()))
        {
            curr=s.erase(curr,curr+oldVal.size());
            curr=s.insert(curr,newVal.begin(),newVal.end());
            curr+=newVal.size();
        }
        else ++curr;
    }
    return s;
}

string replace_func1(string &s,const string&oldVal,const string&newVal)
{
    string::size_type i=0;
    while(i!=s.size()-oldVal.size())
    {
        if(oldVal==string(s,i,oldVal.size()))
        {
            s.replace(i,oldVal.size(),newVal);
            i+=newVal.size();
        }
        else ++i;
    }
    return s;
}

int main(void)
{
    string str("hello world hello world hello china");
    cout<<replace_func(str,"hello","show")<<endl;
    cout<<replace_func1(str,"show","hello")<<endl;

    return 0;
}
