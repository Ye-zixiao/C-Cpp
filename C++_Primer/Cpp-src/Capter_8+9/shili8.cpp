#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace::std;

bool storeline(const string&filename,vector<string>&store);
void print_sstream(const string&strline);

int main(void)
{
    const string filename="infile.txt";
    vector<string> store;
    storeline(filename,store);//将文件中的每一行保存到store中的每一个元素中
    for(const auto &line:store)//打印每一行中的每一个单词
        print_sstream(line);

    return 0;
}


bool storeline(const string&filename,vector<string>&store)
{
    ifstream in(filename,ifstream::in);
    if(in)
    {
        string temp;
        while(getline(in,temp))
            store.push_back(temp);
        return true;
    }
    else
        return false;
}

void print_sstream(const string&strline)
{
    istringstream instring(strline);
    string temp;
    while(instring>>temp)
        cout<<temp<<' ';//这里可以改成放到vector中的代码
    cout<<endl;
}
