#include<iostream>
#include<string>
#include<cctype>
using namespace::std;

int main(void)
{
    string str="hello world!";
    for(decltype(str.size()) cnt=0;cnt!=str.size()&&!isspace(str[cnt]);++cnt)
        //��δ������Χ�һ�δ�����հ��ַ�
        str[cnt]=toupper(str[cnt]);

    cout<<str<<endl;

    return 0;
}
