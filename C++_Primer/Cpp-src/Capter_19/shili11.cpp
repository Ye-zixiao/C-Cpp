#include<iostream>
#include<typeinfo>
using namespace::std;

struct A{
    virtual ~A(){}
};

struct B:A{};

struct D:A,B{};

void func(A&a){
    cout<<"A"<<endl;
}
void func(B&b){
    cout<<"B"<<endl;
}

int main(void)
{
    D item;
    func(item);

    A*pa=new D();
    delete pa;

    return 0;
}
