#include<iostream>
#include<typeinfo>
using namespace::std;

struct A{
    virtual ~A(){}
};

struct B:virtual A{};

struct D:virtual A,B{};

void func(A&a){
    cout<<"A"<<endl;
}
void func(B&b){
    cout<<"B"<<endl;
}

int main(void)
{
    A*pa=new D();
    delete pa;

    D item;
    func(item);

    return 0;
}
