#include<stdio.h>
int main(void)
{
    int n=0;
    size_t intsize;                     //size_t是使用了typedef机制后的unsigned int或者unsigned long的别名

    intsize=sizeof (int);
    printf("n=%d.n has %zd bytes;all ints have\
 %zd bytes.\n",n,sizeof n,intsize);

    return 0;
}
