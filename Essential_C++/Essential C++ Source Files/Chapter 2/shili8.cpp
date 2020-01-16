#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int *ptr=0;
    int value=12;
    int &rf_value=value;        //引用操作：用rf_value代表value
    cout<<value<<endl;

    rf_value=13;
    cout<<value<<endl;          //对引用操作就是等于对原对象value直接操作

    ptr=&rf_value;              //使用指针，使指针指向原对象，通过解引用（dereference）对原对象直接操作
    *ptr=14;
    cout<<value<<endl;
                                /*通过上面可以看出，指针和引用操作原理相同，
                                但两者的概念有点不同，用法也稍微有点不同*/
    return 0;
}
