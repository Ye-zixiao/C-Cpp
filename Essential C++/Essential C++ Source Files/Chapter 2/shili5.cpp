#include<iostream>
using namespace std;

bool fibo_seq(int pos,int &elem);

int main(void)
{
    int pos;
    int value;

    while(true)
    {
        cout<<"Enter the seq_num for this program: ";
        cin>>pos;
        if(fibo_seq(pos,value))
            cout<<"Result:"<<value<<endl;
        else
            cout<<"Input error"<<endl;

        cout<<"Would you like to keep this program?(y/n)";
        char user_rsp;
        cin>>user_rsp;
        if(user_rsp=='n'||user_rsp=='N')
            break;
        cout<<endl;
    }

    return 0;
}

bool fibo_seq(int pos,int &elem)
{
    if(pos<1||pos>1024)
    {
        elem=-1;
        return false;
    }
    else
    {
        int num_1=1,num_2=1;
        elem=1;

        for(int i=3;i<=pos;i++)
        {
            elem=num_1+num_2;
            num_1=num_2;
            num_2=elem;
        }

        return true;
    }
}
