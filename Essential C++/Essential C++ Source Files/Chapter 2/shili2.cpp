#include<iostream>
#include<cstdlib>
using namespace std;

bool fibo_elem(int pos,int *elem);

int main(void)
{
    cout<<"Enter the position of the fibonacci sequence: ";
    int pos;
    int value;
    cin>>pos;
    if(fibo_elem(pos,&value))
        cout<<"Result:"<<value<<endl;
    else
        cout<<"You enter a wrong number"<<endl;

    return 0;
}

bool fibo_elem(int pos,int *elem)
{
    if(pos<1||pos>1024)
    {
        *elem=0;
        return false;
    }
    else
    {
        *elem=1;
        int n_1=1,n_2=1;

        for(int i=3;i<=pos;i++)
        {
            *elem=n_1+n_2;
            n_2=n_1;
            n_1=*elem;
        }
        return true;
    }
}
