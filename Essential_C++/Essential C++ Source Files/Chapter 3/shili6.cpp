#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;

int main(void)
{
    deque<int> d_line;
    int value;
    cout<<"Enter: ";
    cin>>value;

    d_line.push_back(value);            //��deque���������˼���Ԫ��
    cout<<d_line.front()<<endl;         //��ȡdeque��������ǰ��Ԫ��
    d_line.pop_front();                 //ɾ��deque��������ǰ��Ԫ��
    if(d_line.empty())                  //�ж�deque�����Ƿ�Ϊ��
        cout<<"Now,it's empty!"<<endl;

    return 0;
}
