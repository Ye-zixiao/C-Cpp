#include<iostream>
using namespace std;

bool print_sequence(int pos);

int main(void)
{
    cout<<"Please enter the number of the seq£º ";
    int pos;
    cin>>pos;
    print_sequence(pos);

    return 0;
}

bool print_sequence(int pos)
{
    if(pos<=0||pos>1024)
    {
        cerr<<"Error"<<endl;
        return false;
    }
    else
    {
        cout<<"The Fibonacci sequence for "
            <<pos<<" positions:"<<endl;
        if(pos==1)
            cout<<"1 ";
        else if(pos>=2)
            cout<<"1 1 ";

        int num_1=1,num_2=1;
        int elem=1;
        for(int i=3;i<=pos;i++)
        {
            elem=num_1+num_2;
            num_1=num_2;
            num_2=elem;
            cout<<elem<<(i%10? " ":"\n");
        }
        cout<<endl;

        return true;

    }
}
