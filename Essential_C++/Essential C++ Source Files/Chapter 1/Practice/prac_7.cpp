#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
    ifstream infile("practice.txt");
    ofstream outfile("out_practice.txt");
    if(!infile)
    {
        cerr<<"Can't open input file"<<endl;
        return -1;
    }
    if(!outfile)
    {
        cerr<<"Can't open output file"<<endl;
        return -2;
    }

    string word;
    vector<string> text;
    while(infile>>word)                     /*�����ַ�������infile>>word����������������ַ��������б����ţ�
                                                >>���뵽vector�Ὣ������һͬʱΪ�ַ����Ĳ��֣�������Ǹ���һ��
                                                �ո��Ǿͻ��ӱ�����Ϊ������һ���ַ�����
                                                >>����ȡ�հ׺ͻس�����*/
        text.push_back(word);

    /*����ǰ���������ļ���ӡ����Ļ��*/
    cout<<"Unsorted text:\n";
    for(int i=0;i<text.size();i++)
        cout<<text[i]<<" ";
    cout<<endl;

    /*����֮��������ļ�����:*/
    sort(text.begin(),text.end());          //��text��������
    outfile<<"After sorted:\n";
    for(int i=0;i<text.size();i++)
        outfile<<text[i]<<" ";
    outfile<<endl;

    return 0;
}
