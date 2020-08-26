#include<iostream>
#include<string>
#include<cctype>
using namespace::std;

int main(void)
{
    string str="hello world!";
    for(decltype(str.size()) cnt=0;cnt!=str.size()&&!isspace(str[cnt]);++cnt)
        //ÈôÎ´³¬³ö·¶Î§ÇÒ»¹Î´Óöµ½¿Õ°××Ö·û
        str[cnt]=toupper(str[cnt]);

    cout<<str<<endl;

    return 0;
}
