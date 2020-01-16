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

    d_line.push_back(value);            //在deque容器的最后端加入元素
    cout<<d_line.front()<<endl;         //读取deque容器的最前端元素
    d_line.pop_front();                 //删除deque容器的最前端元素
    if(d_line.empty())                  //判断deque容器是否为空
        cout<<"Now,it's empty!"<<endl;

    return 0;
}
