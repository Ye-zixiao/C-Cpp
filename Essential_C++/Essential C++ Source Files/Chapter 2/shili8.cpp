#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int *ptr=0;
    int value=12;
    int &rf_value=value;        //���ò�������rf_value����value
    cout<<value<<endl;

    rf_value=13;
    cout<<value<<endl;          //�����ò������ǵ��ڶ�ԭ����valueֱ�Ӳ���

    ptr=&rf_value;              //ʹ��ָ�룬ʹָ��ָ��ԭ����ͨ�������ã�dereference����ԭ����ֱ�Ӳ���
    *ptr=14;
    cout<<value<<endl;
                                /*ͨ��������Կ�����ָ������ò���ԭ����ͬ��
                                �����ߵĸ����е㲻ͬ���÷�Ҳ��΢�е㲻ͬ*/
    return 0;
}
