#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"StrBlob.h"
using namespace::std;

int main(void)
{
    StrBlob text;
    string line;
    ifstream infile("infile.txt",ifstream::in);
    if(!infile){
        cerr<<"Can't open this file"<<endl;
        return -1;
    }

    while(getline(infile,line))
        text.push_back(line);
    for(auto iter=text.begin();iter!=text.end();++iter)
        cout<<*iter<<endl;

    return 0;
}
