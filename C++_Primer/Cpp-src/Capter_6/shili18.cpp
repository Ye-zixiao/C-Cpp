#include<iostream>
#include<string>
using namespace::std;

inline const string &
shorterString(const string &str1,const string &str2)
{
    return (str1.size()<str2.size())?str1:str2;
}

int main(void)
{
    cout<<shorterString("hello","yes")<<endl;

    return 0;
}
