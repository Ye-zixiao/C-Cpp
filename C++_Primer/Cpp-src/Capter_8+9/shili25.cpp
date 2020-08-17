#include<iostream>
#include<vector>
using namespace::std;

int main(void)
{
    vector<int> ivec;
    for(size_t i=0;i<10;++i)
        ivec.push_back(i);

    for(auto iter=ivec.begin();iter!=ivec.end();)
        if(*iter&0x1){
            ivec.insert(iter,*iter);
            iter+=2;
        }
        else iter=ivec.erase(iter);

    for(auto i:ivec)cout<<i<<' ';cout<<endl;

    return 0;
}
