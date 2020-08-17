#include<iostream>
using namespace::std;

struct A{
    virtual ~A(){}
};

struct B:A{};
struct D:A,B{};
/*
void func(A*pa){
    cout<<"A"<<endl;
}*/

void func(B*pa){
    cout<<"B"<<endl;
}

void func(A&a){
    cout<<"A&"<<endl;
}/*
void func(B&b){
    cout<<"B&"<<endl;
}*/

int main(void)
{
    D item;
    func(&item);
    func(item);

    B* pb=new D();
    delete pb;

    //A* pa=new D();
    //delete pa;

    return 0;
}
