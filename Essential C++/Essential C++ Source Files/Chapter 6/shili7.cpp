#include<iostream>
using namespace std;

/*----------------没有引入无类型模板参数的类--------------*/
class Test
{
public:
    void hello(void)
    {
        cout<<"hello world!"<<endl;
    }
};

class Testfor:public Test
{
public:
    void haha(void)
    {
        hello();
    }
};

/*-----------------引入无类型模板参数的模板类---------------*/
template<int max=0>
class No_par
{
public:
    void hellk(void)
    {
        cout<<"hello motor"<<endl;
    }
};

template<int max=10>
class No_para:public No_par<max>
{
public:
    void hahak(void)
    {
        this->hellk();      /*这里就看出了模板基类与一般的基类的区别，一般的基类会沿着类
                        的作用域一层一层的往上找，知道找到该函数的声明。但是模板类不会干
                        这些无用功，是因为它知道在后续自己被 “实例化”之后，该函数可能根本就不存在*/

    }
};

/*----------------引入无类型模板参数的模板类继承非模板类------------------*/
template<int max=0>
class Inter:public Test
{
public:
    void joker(void)
    {
        cout<<"max="<<max<<endl;
        hello();
    }
};

int main(void)
{
    Testfor hh;
    hh.haha();

    No_para<9> haha2;
    haha2.hahak();

    Inter<99> inter_temp;
    inter_temp.joker();

    return 0;
}
