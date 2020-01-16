/*---------这是第一章的编程练习题-----------
-----------功能：一种计量单位转换-----------*/
#include<stdio.h>
int main(void)                                    //可能在新标准中淘汰这种 int main() 的写法，目前C99和C11还是支持的
{
    int yingcun,limi;

    printf("请输入英寸数:\n");
    scanf("%d",&yingcun);
    limi=2*yingcun;                             //若把这个语句放在第一个printf前面就会发现错误
    printf("厘米数是:%d",limi);        //调试之后基本可以确定存在错误
    getchar();                                           //用以键入推出
    return 0;
}
