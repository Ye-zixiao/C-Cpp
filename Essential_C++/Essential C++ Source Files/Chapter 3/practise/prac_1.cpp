#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<fstream>
#include<iterator>
#include<map>
using namespace std;

int main(void)
{
    ifstream in_file("in_file.txt");
    if(!in_file)
    {
        cerr<<"Error"<<endl;
        return -1;
    }

    string init[6]={"a","an","or","the","and","but"};
    set<string> iset(init,init+6);                      //生成排除string集
    map<string,int> imap;
    string word;

    while(in_file>>word)                                //将文件中的string数据读入
    {
        if(iset.count(word))                            //如果这个字符串是在排除集中，不加入
            continue;
        imap[word]++;
    }

    map<string,int>::iterator iter=imap.begin();
    for(;iter!=imap.end();iter++)                       //打印输出imap中的数据
        cout<<"key: "<<iter->first
            <<" ,value: "<<iter->second<<endl;

    return 0;
}
