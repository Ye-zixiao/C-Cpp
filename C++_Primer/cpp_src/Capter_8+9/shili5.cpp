#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace::std;

ostream& print(const string&filename,ostream&os)
{
    ifstream in(filename,ifstream::in);
    if(in)
    {
        char ch;
        while(in>>ch)
            os<<ch;
    }
    else
        cerr<<"error"<<endl;
    return os;
}

int main(void)
{
    const string infile="infile.txt";
    const string outfile="outfile.txt";

    ofstream out(outfile,ofstream::out|ofstream::trunc);//�Խض�ģʽ������ļ�
    if(out)
        print(infile,out)<<endl;
    else
        cerr<<"error"<<endl;

    out.close();//�ر��ļ���
    out.open(outfile,ofstream::out|ofstream::app);//�Ը���ģʽ���ļ�
    if(out)
        print(infile,out)<<endl;
    else
        cerr<<"error"<<endl;

    return 0;
}
