/*--------��ʾʹ��sizeof��ʾ��ǰ����������ռ�õ��ֽ�-------*/
#include<stdio.h>
int main(void)
{
    printf("Type int has a size of %zd bytes.\n",sizeof(int));                  //int�ڵ�ǰϵͳռ����4���ֽ�
    printf("Type char has a size of %zd bytes.\n",sizeof(char));                //char�ڵ�ǰϵͳռ����1���ֽ�
    printf("Type long has a size of %zd bytes.\n",sizeof(long));                //long�ڵ�ǰϵͳռ����4���ֽ�
    printf("Type short has a size of %zd bytes.\n",sizeof(short));              //short�ڵ�ǰϵͳռ����2���ֽ�
    printf("Type long long has a size of %zd bytes.\n",sizeof(long long));      //long long�ڵ�ǰϵͳռ����8���ֽ�
    printf("Type float has a size of %zd bytes.\n",sizeof(float));              //float�ڵ�ǰϵͳռ����4���ֽ�
    printf("Type double has a size of %zd bytes.\n",sizeof(double));            //double�ڵ�ǰϵͳռ����8���ֽ�
    printf("Type long double has a size of %zd bytes.\n",sizeof(long double));  //long double�ڵ�ǰϵͳռ����8���ֽ�

    return 0;
}
