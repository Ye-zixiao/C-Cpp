#include<iostream>

/*
*ע�����������code::blocks�ǲ�����������ͨ����
*/

int main(void)
{
    constexpr int value = 10;//value��һ���������ʽ
    std::cout << value << std::endl;

    //value = 19l;
    const int* pvalue = &value;//����һ��ָ��const��ָ��ָ�������ʽvalue
    constexpr const int* ppvalue = &value;//ppvalue��һ��ָ��const��constָ��

    int test_value = 10;
    constexpr int* pppvalue = &test_value;

    std::cout << *pppvalue << std::endl;
    *pppvalue = 99;
    std::cout << *pppvalue << std::endl;

    return 0;
}

