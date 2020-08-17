#include<iostream>
#include<string>
using namespace::std;

int main(int argc,char *argv[])
{
    cout<<argc<<endl;
    if(argc<3)
        cerr<<"argv is not enough!"<<endl;
    string str1(argv[1]);
    string str2(argv[2]);
    cout<<str1+' '+str2<<endl;

    return 0;
}
