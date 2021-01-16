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
    cout<<numbers<<endl;//ʹ��find����������ҹؼ��ֵĸ���value

    string search_word("love");
    cout<<words.count(search_word)<<endl;//ʹ�÷����㷨count��������ҹؼ��ֵĸ���value
    return 0;
}
