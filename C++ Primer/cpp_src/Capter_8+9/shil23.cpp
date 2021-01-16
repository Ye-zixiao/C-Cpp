#include<iostream>
#include<string>
#include<forward_list>
using namespace::std;

void find_insert(forward_list<string>&flist,string s1,string s2)
{
    bool flag=false;
    auto pre=flist.before_begin();
    for(auto iter=flist.begin();iter!=flist.end();)
    {
        if(*iter==s1){
            flag=true;
            pre=iter;
            iter=flist.insert_after(iter,s2);
        }
        else{
            pre=iter;++iter;
        }
    }
    if(!flag)
        flist.insert_after(pre,s2);
}

int main(void)
{
    forward_list<string> flist{"hello","world","me"};
    find_insert(flist,"kk","show");
    for(auto i:flist)cout<<i<<' ';cout<<endl;

    return 0;
}
