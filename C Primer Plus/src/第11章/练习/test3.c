#include<stdio.h>
int main(void)
{
    int strlen(const char *str);            //ע�����������VS2019�в�û��ʲôʵ�ʵ�����
    int size;
    size=strlen("I love you!");
    printf("strlen of this is %d\n",size);

    return 0;
}

int strlen(const char *str)
{
    int ct=0;
    while(*str!='\0')
        ct++;

    return ct;
}
