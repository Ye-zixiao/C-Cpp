#include<iostream>
using namespace std;

int main(void)
{
    const int size_max=120;
    int arr[size_max];
    int i=0;
    int sum=0;
    int in_num;

    cout<<"Enter the number for this program(enter 'q' to quit): ";
    while(cin>>in_num&&i<size_max)
        arr[i++]=in_num;

    int size_input=i;
    for(;i>0;i--)
        sum+=arr[i-1];
    if(size_input)
    {
        int average=sum/size_input;
        cout<<"The sum of this "<<size_input
            <<" elements is "<<sum
            <<",and average is "<<average<<endl;
    }
    else
        cout<<"No data in your array."<<endl;

    return 0;
}
