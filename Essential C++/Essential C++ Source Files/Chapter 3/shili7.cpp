#include<iostream>
#include<list>
using namespace std;

template<typename elemtype>
void display(const list<elemtype> &list_arr);               //输出打印当前的双向链表

template<typename elemtype>
void insert_elem(list<elemtype> &list_arr,elemtype value);  //插入元素到当前的链表当中

int main(void)
{
    int arr[4]={3,6,11,23};
    list<int> list_arr(arr,arr+4);
    display(list_arr);

    while(true)
    {
        int value;
        cout<<"Enter value: ";
        cin>>value;
        insert_elem(list_arr,value);
        cout<<"Now:"<<endl;
        display(list_arr);

        cout<<endl<<"Keep?(y/n)";
        char rsp;
        cin>>rsp;
        if(rsp=='n'||rsp=='N')
            break;
    }
    return 0;
}

template<typename elemtype>
void display(const list<elemtype> &list_arr)
{
    typename list<elemtype>::const_iterator iter=list_arr.begin();

    for(;iter!=list_arr.end();iter++)
        cout<<*iter<<' ';
    cout<<endl;
}

template<typename elemtype>
void insert_elem(list<elemtype> &list_arr,elemtype value)
{
    typename list<elemtype>::iterator iter=list_arr.begin();//泛型指针指向链表首元素的地址

    for(;iter!=list_arr.end();iter++)
        if(*iter>=value)                                    //如果有元素大于value，就插入到它的前面
        {
            list_arr.insert(iter,value);
            break;
        }
    if(iter==list_arr.end())                                //否则插入到最后面
        list_arr.push_back(value);
}
