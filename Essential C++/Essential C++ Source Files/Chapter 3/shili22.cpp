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
    istream_iterator<string> inst(cin);     //绑定输入设备
    istream_iterator<string> eof;
    vector<string> text;

    copy(inst,eof,back_inserter(text));     //将输入数据拷贝到text中
    sort(text.begin(),text.end());

    ostream_iterator<string> os(cout," ");  //绑定输出设备
    copy(text.begin(),text.end(),os);       //将text数据拷贝到输出设备中

    cout<<endl;

    return 0;
}
