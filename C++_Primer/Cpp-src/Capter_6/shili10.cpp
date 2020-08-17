#include<iostream>
using namespace::std;

int &get(int *arr,int index){return arr[index];}

int main(void)
{
    int arr[10];
    for(int i=0;i!=10;++i)
        get(arr,i)=i;

    for(const auto &i:arr)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}
