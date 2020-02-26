#include<iostream>
using std::cout;
using std::endl;

void print(const int arr[10]);

int main(void)
{
    int arr[10]={1,2,};
    print(arr);

    return 0;
}

void print(const int arr[10])
{
    for(size_t i=0;i<10;++i)
        cout<<arr[i]<<' ';
    cout<<endl;
    return;
}
