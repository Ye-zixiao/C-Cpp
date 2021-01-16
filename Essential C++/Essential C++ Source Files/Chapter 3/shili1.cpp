#include<iostream>
#include<vector>
using namespace std;

template<typename elemtype>
const elemtype *find_elem(const vector<elemtype> &seq,int value);

int main(void)
{
    int arr[4]={1,2,3,4};
    vector<int> vec_arr(arr,arr+4);

    if(!find_elem(vec_arr,4))
        cout<<"Not find!"<<endl;
    else
        cout<<"Find!"<<endl;

    return 0;
}

template<typename elemtype>
const elemtype *find_elem(const vector<elemtype> &seq,int value)
{
    for(int i=0;i<seq.size();i++)
        if(seq[i]==value)
            return &seq[i];
    return 0;
}
