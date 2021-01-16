#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(void)
{
    ofstream outfile("person_data.txt",ios_base::app);          //以追加模式写入文件
    if(!outfile)
    {
        cerr<<"You can't open this file.\n";
    }
    else
    {
        bool agree=true;
        cout<<"Please enter the name and the age.\n";
        while(agree)
        {
            cout<<"Enter the name: ";
            string name;
            cin>>name;
            cout<<"Enter the age: ";
            int age;
            cin>>age;

            outfile<<name<<' '               //将输入写入到文件中
                <<age<<endl;
            cout<<"Would you like to enter another person?(y/n)\n";
            char user_rsp;
            cin>>user_rsp;
            if(user_rsp=='n'||user_rsp=='N')
                agree=false;
        }
    }

    return 0;
}
