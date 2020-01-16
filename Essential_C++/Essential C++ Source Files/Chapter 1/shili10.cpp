#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(void)
{
    ifstream infile("person_data.txt");
    if(!infile)
        cerr<<"You can't open this file.\n";
    else
    {
        bool find=false;
        string lookfor_name;
        string name;
        int age;

        cout<<"Enter the name that you want to look up: ";
        cin>>lookfor_name;
        while(infile>>name)                                 /*������ļ��ж�ȡ��һ��string����󣬾ͻ᷵��һ��true��
                                                                �������ĩβ�˾ͻ᷵��һ��false          */
        {
            infile>>age;                                    //�ڶ�ȡ��һ��string���ȡһ��int����������
            if(name==lookfor_name)
            {
                cout<<"We find the name that you want.\n"
                    <<name<<" is a "
                    <<age<<" year(s) old person.\n";
                find=true;
                break;
            }
        }
        if(!find)
            cout<<"Sorry,we can't find this person.\n";
    }

    return 0;
}
