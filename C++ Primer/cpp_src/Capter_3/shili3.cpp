#include<iostream>
#include<string>
using namespace::std;

int main(void)
{
    string str1,str2;
    cin>>str1>>str2;
    if(str1==str2)
        cout<<"They are the fucking same!"<<endl;
    else
        cout<<"The bigger one is "<<(str1>str2?str1:str2)<<endl;

    if(str1.length()==str2.length())
        cout<<"They have the fucking same length!"<<endl;
    else
        cout<<"The longer one is "<<(str1.size()>str2.size()?str1:str2)<<endl;

    return 0;
}
