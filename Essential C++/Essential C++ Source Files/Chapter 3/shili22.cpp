#include<iostream>
#include<iterator>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

int main(void)
{
    //istream_iterator<string> inst=cin;
    istream_iterator<string> inst(cin);     //�������豸
    istream_iterator<string> eof;
    vector<string> text;

    copy(inst,eof,back_inserter(text));     //���������ݿ�����text��
    sort(text.begin(),text.end());

    ostream_iterator<string> os(cout," ");  //������豸
    copy(text.begin(),text.end(),os);       //��text���ݿ���������豸��

    cout<<endl;

    return 0;
}
