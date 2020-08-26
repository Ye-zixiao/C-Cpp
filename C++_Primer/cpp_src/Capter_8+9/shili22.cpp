#include<iostream>
#include<string>
#include<forward_list>
using namespace::std;

void find_insert(forward_list<string>&flist,string s1,string s2)
{
    bool flag=false;
    for(auto iter=flist.begin();iter!=flist.end();)
        if(*iter==s1){
            iter=flist.insert_after(iter,s2);
            flag=true;
        }else ++iter;

    if(!flag)//尾后指针并不是指向最后一个元素的指针，所以这个添加到末尾的程序是不行的
        flist.insert_after(flist.end(),s2);
}

void find_first_insert(forward_list<string>&flist,string s1,string s2)
{
    for(auto iter=flist.begin();iter!=flist.end();++iter)
        if(*iter==s1){
            flist.insert_after(iter,s2);return;//插入后立即走人
        }
    //若flist中没有找到s1字符串，那么就在最后面加上s2字符串
    flist.insert_after(flist.end(),s2);
}

int main(void)
{
    forward_list<string> flist{"hello","world","show","world","me"};
    find_insert(flist,"kk","to");
    for(auto i:flist)cout<<i<<' ';cout<<endl;
    find_first_insert(flist,"world","google");
    for(auto i:flist)cout<<i<<' ';cout<<endl;

    return 0;
}
