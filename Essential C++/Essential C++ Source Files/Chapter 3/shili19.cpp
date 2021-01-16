#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void)
{
    map<string,int> words;
    string tword;
    while(cin>>tword)
        words[tword]++;

    map<string,int>::iterator iter=words.begin();
    for(;iter!=words.end();iter++)
        cout<<"key: "<<iter->first
            <<" value: "<<iter->second<<endl;

    int numbers=0;
    iter=words.find("love");
    if(iter!=words.end())
        numbers=iter->second;
    cout<<numbers<<endl;//使用find函数计算查找关键字的个数value

    string search_word("love");
    cout<<words.count(search_word)<<endl;//使用泛型算法count来计算查找关键字的个数value
    return 0;
}
