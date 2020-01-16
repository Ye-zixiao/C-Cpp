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
    set<string> iset(init,init+6);                      //�����ų�string��
    map<string,int> imap;
    string word;

    while(in_file>>word)                                //���ļ��е�string���ݶ���
    {
        if(iset.count(word))                            //�������ַ��������ų����У�������
            continue;
        imap[word]++;
    }

    map<string,int>::iterator iter=imap.begin();
    for(;iter!=imap.end();iter++)                       //��ӡ���imap�е�����
        cout<<"key: "<<iter->first
            <<" ,value: "<<iter->second<<endl;

    return 0;
}
