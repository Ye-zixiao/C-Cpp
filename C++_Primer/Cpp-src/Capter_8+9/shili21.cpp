#include<iostream>
#include<forward_list>
#include<list>
using namespace::std;

int main(void)
{
    forward_list<int> flist{1,2,3,4,5,6,7,8,9,10};
    auto pre=flist.before_begin();
    for(auto curr=flist.begin();curr!=flist.end();)
        if(*curr&0x1)
            curr=flist.erase_after(pre);
        else{
            pre=curr;++curr;
        }

    for(auto i:flist)cout<<i<<' ';cout<<endl;

    return 0;
}
