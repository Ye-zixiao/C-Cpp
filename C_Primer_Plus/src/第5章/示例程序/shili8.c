#include<stdio.h>
int main(void)
{
    int n=0;
    size_t intsize;                     //size_t��ʹ����typedef���ƺ��unsigned int����unsigned long�ı���

    intsize=sizeof (int);
    printf("n=%d.n has %zd bytes;all ints have\
 %zd bytes.\n",n,sizeof n,intsize);

    return 0;
}
