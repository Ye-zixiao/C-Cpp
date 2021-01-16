#include<iostream>
#include<list>
using namespace std;

template<typename elemtype>
void display(const list<elemtype> &list_arr);               //�����ӡ��ǰ��˫������

template<typename elemtype>
void insert_elem(list<elemtype> &list_arr,elemtype value);  //����Ԫ�ص���ǰ��������

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
    typename list<elemtype>::iterator iter=list_arr.begin();//����ָ��ָ��������Ԫ�صĵ�ַ

    for(;iter!=list_arr.end();iter++)
        if(*iter>=value)                                    //�����Ԫ�ش���value���Ͳ��뵽����ǰ��
        {
            list_arr.insert(iter,value);
            break;
        }
    if(iter==list_arr.end())                                //������뵽�����
        list_arr.push_back(value);
}
