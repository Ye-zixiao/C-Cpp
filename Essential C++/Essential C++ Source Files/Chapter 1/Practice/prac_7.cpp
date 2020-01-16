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
    while(infile>>word)                     /*对于字符串本身，infile>>word处理正常，且如果字符串后面有标点符号，
                                                >>读入到vector会将标点符号一同时为字符串的部分，当如果是隔开一个
                                                空格，那就会视标点符号为单独的一个字符串。
                                                >>不读取空白和回车换行*/
        text.push_back(word);

    /*排序前，将输入文件打印在屏幕上*/
    cout<<"Unsorted text:\n";
    for(int i=0;i<text.size();i++)
        cout<<text[i]<<" ";
    cout<<endl;

    /*排序之后，输出到文件当中:*/
    sort(text.begin(),text.end());          //对text进行排序
    outfile<<"After sorted:\n";
    for(int i=0;i<text.size();i++)
        outfile<<text[i]<<" ";
    outfile<<endl;

    return 0;
}
