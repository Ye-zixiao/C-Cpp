#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

int main()
{
    const int name_size=128;
    char user_name[name_size];
    cout<<"Please enter your name: ";
    cin>>setw(name_size)>>user_name;            //���������ַ����������ַ�����Ҳ�����ܳ���char֮�����������

    switch(strlen(user_name))
    {
        case 127:
            cout<<"Name too big."<<endl;
            break;
        default:
            cout<<"Hello,"<<user_name<<".\n";
            break;
    }

    return 0;
}
