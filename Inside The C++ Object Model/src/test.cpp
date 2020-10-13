#include <iostream>
#include <cstdio>

struct Base1{
    int value1;
};

struct Base2{
    int value2;
};

struct Derived1:Base1,Base2{};

struct Derived2:Base1,Base2{
    int value3;
};

void func1(int Derived1::*dmp,Derived1*pd){
    std::cout<<pd->*dmp<<std::endl;
}

void func2(Derived1*pd){
    int Base2::*bmp=&Base2::value2;

    func1(bmp,pd);
}

int main(void)
{
    Derived1 d;d.value1=1;d.value2=2;
    func2(&d);

    printf("&Base1::value1: %d\n",&Base1::value1);
    printf("&Base2::value2: %d\n",&Base2::value2);
    printf("&Derived1::value1: %d\n",&Derived1::value1);
    printf("&Derived1::value2: %d\n",&Derived1::value2);
    //对于涉及到多重继承的类数据成员指针（指向基类数据成员）表示的偏移量都为0
    //这一事实可能是由于受到编译器的的特殊处理的影响
    printf("&Derived2::value1: %d\n",&Derived1::value1);
    printf("&Derived2::value2: %d\n",&Derived2::value2);
    printf("&Derived2::value3: %d\n",&Derived2::value3);

    return 0;
}