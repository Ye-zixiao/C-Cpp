#include<vector>
#include<string>
#include<iostream>
#include<list>
using namespace::std;

int main(void)
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    vector<int> ivec(begin(arr),end(arr));
    list<int> ilist(begin(arr),end(arr));

    for(auto iter=ivec.begin();iter!=ivec.end();)
        if(*iter&0x1)
            iter=ivec.erase(iter);
        else
            ++iter;

    for(auto iter=ilist.begin();iter!=ilist.end();)
        if(*iter&0x1)
            ++iter;
        else
            iter=ilist.erase(iter);

    for(auto i:ivec)cout<<i<<' ';cout<<endl;
    for(auto i:ilist)cout<<i<<' ';cout<<endl;

    return 0;
}
