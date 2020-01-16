#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(void)
{
    fstream iofile("person_data.txt",ios_base::app|ios_base::in);
    if(!iofile)
        cerr<<"You can't open this file.\n";
    else
    {
        iofile.seekg(0);                                        //将文件指示到最开始处
        string name;
        int age;

        cout<<"In this file, we records:\n";
        while(iofile>>name)
        {
            iofile>>age;
            cout<<name<<' '
                <<"is a "
                <<age<<" year(s) old person.\n";
        }
        cout<<'\n';

        while(1)
        {
            cout<<"Would you like to add some person's data?\n";
            char user_rsp;
            cin>>user_rsp;
            if(user_rsp=='n'||user_rsp=='N')
                break;

            cout<<"Enter the name: ";
            cin>>name;
            cout<<"Enter the age: ";
            cin>>age;
            iofile<<name<<' '<<age<<endl;                       //将数据导入到文件之中
        }
        cout<<"Goodbye.\n";
    }

    return 0;
}
