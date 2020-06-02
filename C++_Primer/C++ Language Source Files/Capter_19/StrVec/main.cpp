#include<iostream>
#include"StrVec.h"
#include<string>
using namespace::std;

int main(void)
{
    StrVec strvec{"hello","world","china","joker"};
    for(auto iter=strvec.begin();iter!=strvec.end();++iter)
        cout<<*iter<<' ';
    cout<<endl;
    return 0;
}
