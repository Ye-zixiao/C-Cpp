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
        while(infile>>name)                                 /*如果从文件中读取到一个string类对象，就会返回一个true；
                                                                如果读到末尾了就会返回一个false          */
        {
            infile>>age;                                    //在读取完一个string后读取一个int的数据类型
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
