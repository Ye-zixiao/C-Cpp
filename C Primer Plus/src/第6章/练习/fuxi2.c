#include<stdio.h>
int main(void)
/*{
    int i,j;
    const char DOL='$';
    const int HANG=4;   //����
    const int LIE=8;    //����

    for(i=1;i<=HANG;i++)
    {
        for(j=1;j<=LIE;j++)
            printf("%c",DOL);//ɵ�ƣ���������ֱ�Ӵ�ӡ�����ַ�����������
        printf("\n");
    }

    return 0;
}*/

{
    int i;
    char ch;

    for(i=0,ch='A';i<4;i++,ch+=2*i)/*����������еĶ��Ŷ���һ�����е㣬
                                        ������ch+=2*i����֮ǰi++�Ѿ����
                                        ���������Ե�һ�ν���ѭ����ʱi�Ѿ��Լӳ�Ϊ1*/
        printf("%c",ch);
    return 0;
}
