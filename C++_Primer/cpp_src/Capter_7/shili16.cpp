#include<iostream>
using namespace::std;

class UseTest;

class Test{
    friend class UseTest;/*��Ԫ��������Ϊ��Ԫ�������Բ�ǿ���������Testǰ��������
                        �����뱣֤Test�еĳ�Ա����������Ԫ���еĳ�Ա����ʱ���뱣
                        ֤��UseTest��Ԫ�������Ԫ���������еĳ�Ա�����ɼ�*/
public:
    Test()=default;
    Test(int val):value(val){}
    int get_value(const UseTest&ut) const;

private:
    int value=0;
};

/*
inline int Test::get_value(const UseTest&ut) const
            /*��ΪUseTest����Ȼ���������ˣ�����������Ԫ��������Test��
            ��Ա����get_valueʹ����UseTest��ʵ�壬���Ա������Ҫ��UseTest��֮ǰ�ͱ��뱻���壬��ε����ʲ�һ����*//*
{
    return ut.get_value(*this);
}
*/

class UseTest{
public:
    UseTest()=default;
    //UseTest(int val):value(val){}
    int get_value(const Test&item) const{ return item.value;}

private:

};

///*
inline int Test::get_value(const UseTest&ut) const
{
    return ut.get_value(*this);
}
//*/

int main(void)
{
    Test test(5);
    UseTest ut;
    cout<<test.get_value(ut)<<endl;

    return 0;
}
