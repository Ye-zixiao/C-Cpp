/*-------�����ַ�ʽ��ʾ�����͵�ֵ--------*/
#include<stdio.h>
int main()
{
    float aboat=32000.0;
    double abet=2.14e9;
    long double dip=5.32e-5;

    printf("%f can be written %e\n",aboat,aboat);                   //���������ֱ��ӡ��ʮ��������ָ����ʽ
    printf("And it's %a in hex ,powers of 2 notation\n",aboat);      //����������ӡ��ʮ����������ʽ
    printf("%f can be written %e\n",abet,abet);                     //��˫���ȸ�������ӡ��ʮ��������ʽ
    printf("%Lf can be written %Le\n",dip,dip);                     /*����˫���ȸ�������ӡ��ָ����ʽ
                                                                        ���������long double ȷʵ��������ʹ��
                                                                        ������VS2019�����ǿ����������еģ�������Code::Blocks��������ԭ��*/

    return 0;
}

/*
%f--------��ʮ��������ʾ������
%e--------��ָ����ʽ��ʾ������
%a--------��ʮ����������ʾ������
���϶���ͨ����float��double

����Գ�˫����long double��Ҫ��f��e��aǰ�����L����д�����ڷֱ棩
*/
