#include<iostream>
#include<string>
using namespace std;

int main(void)
{
   /* int arr[3]={1,2,3,};
    cout<<arr<<endl;*/

    string user_name;

    cout<<"Please enter your name: ";
    cin>>user_name;                         //�����������հ׺��������
    switch(user_name.size())
    {
        case 0:
            cout<<"No name."<<endl;
            break;
        case 1:
            cout<<"Hello,"
                <<user_name<<endl;
            break;
        default:
            cout<<"Hello,"<<user_name
                <<"--happy to make your acquaitance."<<endl;
            break;
    }

    return 0;
}
