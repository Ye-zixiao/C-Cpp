#include<iostream>
#include<string>
#include<vector>
using namespace::std;

int main(void)
{
    vector<int> num_seq1{1,2,5},num_seq2{1,2,4,3};
    if(num_seq1>num_seq2)
        cout<<"是根据第一个相异元素值来判定vector的大小的！"<<endl;
    else
        cout<<"hehe"<<endl;

    return 0;
}
