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
    istream_iterator<string> inst(in_file);     //绑定输入设备
    istream_iterator<string> eof;
    vector<string> text;

    copy(inst,eof,back_inserter(text));     //将输入数据拷贝到text中
    sort(text.begin(),text.end());

    ostream_iterator<string> os(out_file," ");  //绑定输出设备
    copy(text.begin(),text.end(),os);       //将text数据拷贝到输出设备中

    cout<<endl;

    return 0;
}
