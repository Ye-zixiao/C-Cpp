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

    ofstream out(outfile,ofstream::out|ofstream::trunc);//以截断模式打开输出文件
    if(out)
        print(infile,out)<<endl;
    else
        cerr<<"error"<<endl;

    out.close();//关闭文件绑定
    out.open(outfile,ofstream::out|ofstream::app);//以附加模式打开文件
    if(out)
        print(infile,out)<<endl;
    else
        cerr<<"error"<<endl;

    return 0;
}
