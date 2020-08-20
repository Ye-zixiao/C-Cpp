/*--------演示使用sizeof显示当前数据类型所占用的字节-------*/
#include<stdio.h>
int main(void)
{
    printf("Type int has a size of %zd bytes.\n",sizeof(int));                  //int在当前系统占用了4个字节
    printf("Type char has a size of %zd bytes.\n",sizeof(char));                //char在当前系统占用了1个字节
    printf("Type long has a size of %zd bytes.\n",sizeof(long));                //long在当前系统占用了4个字节
    printf("Type short has a size of %zd bytes.\n",sizeof(short));              //short在当前系统占用了2个字节
    printf("Type long long has a size of %zd bytes.\n",sizeof(long long));      //long long在当前系统占用了8个字节
    printf("Type float has a size of %zd bytes.\n",sizeof(float));              //float在当前系统占用了4个字节
    printf("Type double has a size of %zd bytes.\n",sizeof(double));            //double在当前系统占用了8个字节
    printf("Type long double has a size of %zd bytes.\n",sizeof(long double));  //long double在当前系统占用了8个字节

    return 0;
}
