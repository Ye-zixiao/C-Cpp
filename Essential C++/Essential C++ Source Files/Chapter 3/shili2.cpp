#include<iostream>
#include<vector>
using namespace std;

template<typename elemtype>
const elemtype *find_elem(const elemtype *arr,int size,const elemtype &value);

int main(void)
{
    int arr[4]={1,2,3,4};
    int value=2;
    if(!find_elem(arr,4,value))
        cout<<"Not find"<<endl;
    else
        cout<<"Find"<<endl;

    return 0;
}

/*
template<typename elemtype>
const elemtype *find_elem(const elemtype *arr,int size,const elemtype &value)
{
    if(!arr||size<1)
        return 0;
    else
    {
        for(int i=0;i<size;i++)
            if(arr[i]==value)
                return &arr[i];
        return 0;
    }
}
*/

template<typename elemtype>
const elemtype *find_elem(const elemtype *arr,int size,const elemtype &value)
{
    if(!arr||size<1)
        return 0;
    else
    {
        for(int i=0;i<size;i++,arr++)
            if(*arr==value)
                return arr;
        return 0;
    }
}
