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

    a_list.insert(it,value_arr_2,value_arr_2+4);//��it������֮ǰ����value_arr_2�е�����
    display(a_list);

    a_list.erase(a_list.begin());//ɾ����Ԫ��
    display(a_list);

    it=find(a_list.begin(),a_list.end(),5);
    a_list.erase(it,a_list.end());//ɾ����Χ�ڵ�Ԫ��
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
