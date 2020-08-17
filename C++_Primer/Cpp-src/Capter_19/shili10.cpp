#include<iostream>
#include<typeinfo>
using namespace::std;

struct A{
    virtual ~A(){}
};

struct B{
    virtual ~B(){}
};

struct D:A,B{
};

void func(A&a){}
void func(B&b){}

int main(void)
{
    D item;
    func(item);
    //因为对于派生类D类对象看来，从派生类D到基类A和到基类B的转换都一样好，所以就会引发二义性调用

    A* pa=new D();//不过这个派生类到基类的转换是明确的
    delete pa;

    return 0;
}
