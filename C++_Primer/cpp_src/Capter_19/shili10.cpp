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
    //��Ϊ����������D�����������������D������A�͵�����B��ת����һ���ã����Ծͻ����������Ե���

    A* pa=new D();//������������ൽ�����ת������ȷ��
    delete pa;

    return 0;
}
