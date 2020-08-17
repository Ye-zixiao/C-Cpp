#include<iostream>
#include<vector>
using namespace::std;

void print(const vector<int> &ivec,unsigned index)
{
    if(index>0)
    {
        print(ivec,index-1);
        cout<<ivec[index-1]<<' ';
    }
}

int main(void)
{
    vector<int> ivec(10);
    for(unsigned i=0;i!=10;++i)
        ivec[i]=i;

    print(ivec,10);

    return 0;
}
