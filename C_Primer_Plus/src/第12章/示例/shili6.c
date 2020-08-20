#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int static_store=30;
const char *pcg="String Literal";

int main(void)
{
    int auto_store=40;
    char auto_string[]="Auto char Array";
    int *pi;
    char *pcl;

    pi=(int *)malloc(sizeof(int));
    *pi=35;
    pcl=(char *)malloc(strlen("Dynamic String")+1);
    strcpy(pcl,"Dynamic String");

    printf("static_store全局变量: %d at %p\n",static_store,&static_store);//静态内存
    printf("auto_store自动变量: %d at %p\n",auto_store,&auto_store);      //自动存储
    printf("*pi动态内存: %d at %p\n",*pi,pi);                             //动态内存
    printf("%s全局变量 at %p\n",pcg,pcg);                                 //静态内存
    printf("%s自动变量 at %p\n",auto_string,auto_string);                 //自动存储
    printf("%s动态内存 at %p\n",pcl,pcl);                                 //动态内存
    printf("%s字符常量 at %p\n","Quoted String","Quoted String");         //自动存储

    free(pi);
    free(pcl);
    return 0;
}
/*
volatile 影响编译器编译的结果,指出，volatile 变量是随时可能发生变化的，
与volatile变量有关的运算，不要进行编译优化，以免出错，（VC++ 在产生release
版可执行码时会进行编译优化，加volatile关键字的变量有关的运算，将不进行编译优化。）。
例如：
volatile int i=10;
int j = i;
...
int k = i;
volatile 告诉编译器i是随时可能发生变化的，每次使用它的时候必须从i的地址中读取，
因而编译器生成的可执行码会重新从i的地址读取数据放在k中。
而 优化做法是，由于编译器发现两次从i读数据的代码之间的代码没有对i进行过操作，
它会自动把上次读的数据放在k中。而不是重新从i里面读。这样以来，
如果 i是一个寄存器变量或者表示一个端口数据就容易出错，所以说volatile可以保证对特殊地址的稳定访问，
不会出错。*/
