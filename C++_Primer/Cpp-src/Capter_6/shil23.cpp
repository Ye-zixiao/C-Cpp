#include<iostream>
#include<vector>
#define NDEBUG
using namespace::std;

void print_vector(vector<int>::const_iterator first,vector<int>::const_iterator last)
{
    static size_t cnt=0;
    ++cnt;
#ifndef NDEBUG
    cout<<'\n';
    cout<<__func__<<" operated "<<cnt<<" times"<<endl;
    cout<<" and vector's size is "<<static_cast<size_t>(last-first)<<endl;
#endif // NDEBUG
    if(last-first==0)
        return;
    cout<<*first++<<' ';
    print_vector(first,last);
}

int main(void)
{
    vector<int> ivec(10);
    decltype(ivec.size()) cnt=0;
    for(auto &elem:ivec)
        elem=cnt++;

    print_vector(ivec.cbegin(),ivec.cend());
    return 0;
}
