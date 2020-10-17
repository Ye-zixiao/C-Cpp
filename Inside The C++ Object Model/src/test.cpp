#include <iostream>

class Base1{
public:
    virtual ~Base1()=default;
    virtual void speakClearly(){}
    virtual Base1*clone() const{}

protected:
    float data_base1;
};

class Base2{
public:
    virtual ~Base2()=default;
    virtual void mumble() {}
    virtual Base2*clone() const {}

protected:
    float data_base2;
};

class Derived:public Base1,public Base2{
public:
    virtual ~Derived() override{}
    virtual Derived* clone() const override{}

protected:
    float data_derived;
};

class Test{
public:
    int value1;
};

class Test_Derived:public Test{
public:
    int value2;
};

int main(int argc,char*argv[])
{
    Derived item;
    Test_Derived test_derived;
    std::cout<<"We create derived item"<<std::endl;
    std::cout<<"Test::value1        : "<<&test_derived.value1<<std::endl;
    std::cout<<"Test_Derived::value2: "<<&test_derived.value2<<std::endl;

    return 0;
}