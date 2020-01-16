#include<stdio.h>
void interchange(int *u,int *v);

int main(void)
{
    int x=5,y=10;

    printf("Originally x=%d and y=%d.\n",x,y);
    interchange(&x,&y);                             //将x、y的地址传输给调用的函数（子函数）
    printf("Now, x=%d and y=%d.\n",x,y);

    return 0;
}

void interchange(int *u,int *v)                     //形参中声明两个指针
{
    int temp;

    temp=*u;                                         //将指针u指向的变量的值赋给temp
    *u=*v;                                           //将指针v所指向的变量的值赋给指针u所指向的变量
    *v=temp;                                         //将变量temp的值赋给指针v所指向的变量

    return;
}
