#include<iostream>
/*
int main(void)
{
    constexpr int value=10;
    //const int *const pvalue=&value;
    //constexpr const int *pvalue=&value;����ᱻ��Ϊ��&value���ǳ������ʽ��
    //������vs���ǿ��Եģ�����Ҳ����ʾ���󵫿��Ա�������
    constexpr const int* pvalue=nullptr;

    return 0;
}
*/

int value=10;

int main(void)
{
    //constexpr const int *pvalue=&value;��ʱ��value�ŵ������������ǿ������е�
    constexpr int *pvalue=&value;

    std::cout<<*pvalue<<std::endl;
    *pvalue=199;
    std::cout<<*pvalue<<std::endl;

    return 0;
}
