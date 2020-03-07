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
    storeline(filename,store);//���ļ��е�ÿһ�б��浽store�е�ÿһ��Ԫ����
    for(const auto &line:store)//��ӡÿһ���е�ÿһ������
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
        cout<<temp<<' ';//������Ըĳɷŵ�vector�еĴ���
    cout<<endl;
}
