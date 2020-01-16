#include<iostream>
#include<iterator>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

int main(void)
{
    ifstream in_file("in_file.txt");
    ofstream out_file("out_file.txt");
    if(!in_file||!out_file)
    {
        cerr<<"Open file error!"<<endl;
        return -1;
    }

    //istream_iterator<string> inst=cin;
    istream_iterator<string> inst(in_file);     //�������豸
    istream_iterator<string> eof;
    vector<string> text;

    copy(inst,eof,back_inserter(text));     //���������ݿ�����text��
    sort(text.begin(),text.end());

    ostream_iterator<string> os(out_file," ");  //������豸
    copy(text.begin(),text.end(),os);       //��text���ݿ���������豸��

    cout<<endl;

    return 0;
}
