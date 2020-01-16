#include<iostream>
#include<cstdlib>
using namespace std;

int fibonacci(int pos);

int main(void)
{
    cout<<"Enter the seq_num for fibonacci: ";
    int seq_num;
    cin>>seq_num;
    cout<<"F("<<seq_num<<")"
        <<" is "<<fibonacci(seq_num)
        <<endl;

    return 0;
}

int fibonacci(int pos)
{
    if(pos<1)
    {
        cerr<<"Input error!"<<endl;
        exit(-1);                                       //需要用到c标准库
    }
    else if(pos==1||pos==2)
        return 1;
    else
        return fibonacci(pos-1)+fibonacci(pos-2);
}
