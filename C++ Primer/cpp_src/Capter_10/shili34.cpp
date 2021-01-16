#include<iostream>
#include<vector>
using namespace::std;

int main(void)
{
    vector<int> ivec(10);
    for(decltype(ivec)::size_type i=0;i<ivec.size();++i)
        ivec.at(i)=i;

    for(auto iter=prev(ivec.cend());;--iter)
    {
        cout<<*iter<<' ';
        if(iter==ivec.cbegin())
            break;
    }
    cout<<endl;
    return 0;
}
g
