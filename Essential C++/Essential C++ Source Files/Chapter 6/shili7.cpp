#include<iostream>
using namespace std;

/*----------------û������������ģ���������--------------*/
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

/*-----------------����������ģ�������ģ����---------------*/
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
        this->hellk();      /*����Ϳ�����ģ�������һ��Ļ��������һ��Ļ����������
                        ��������һ��һ��������ң�֪���ҵ��ú���������������ģ���಻���
                        ��Щ���ù�������Ϊ��֪���ں����Լ��� ��ʵ������֮�󣬸ú������ܸ����Ͳ�����*/

    }
};

/*----------------����������ģ�������ģ����̳з�ģ����------------------*/
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
