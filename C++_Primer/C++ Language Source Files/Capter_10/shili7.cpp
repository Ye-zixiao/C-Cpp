#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace::std;

ostream& print(const vector<int> &ivec,ostream&os=cout)
{
    for(auto i:ivec)os<<i<<' ';return os;
}

int main(void)
{
    vector<int> ivec;
    for(vector<int>::size_type i=0;i<20;++i)
    {
        ivec.push_back(i);ivec.push_back(i);
    }
    print(ivec)<<endl;

    sort(ivec.begin(),ivec.end());
    auto erase_iter=unique(ivec.begin(),ivec.end());
    print(ivec)<<endl;
    ivec.erase(erase_iter,ivec.end());
    print(ivec)<<endl;

    return 0;
}


