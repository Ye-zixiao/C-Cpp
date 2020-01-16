#include<iostream>
#include<algorithm>
#include<string>
#include<list>
using namespace std;

template<typename elemtype>
void display(const list<elemtype>& a_list);

int main(void)
{
    int value_arr_1[7]={1,2,3,4,5,6,7,};
    int value_arr_2[4]={2,4,5,7};
    list<int> a_list(value_arr_1,value_arr_1+7);
    list<int>::iterator it=find(a_list.begin(),a_list.end(),5);

    a_list.insert(it,value_arr_2,value_arr_2+4);//在it迭代器之前插入value_arr_2中的数据
    display(a_list);

    a_list.erase(a_list.begin());//删除首元素
    display(a_list);

    it=find(a_list.begin(),a_list.end(),5);
    a_list.erase(it,a_list.end());//删除范围内的元素
    display(a_list);

    return 0;
}

template<typename elemtype>
void display(const list<elemtype>& a_list)
{
    typename list<elemtype>::const_iterator it=a_list.begin();

    for(;it!=a_list.end();it++)
        cout<<*it<<' ';
    cout<<endl;
}
