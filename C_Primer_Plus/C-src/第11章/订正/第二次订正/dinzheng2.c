/*-第8题*/
#include<stdio.h>
#include<string.h>
char *string_in(const char *st1,const char *st2);

int main(void)
{
    if(string_in("haagts","at"))
        puts("find");
    else
        puts("no");

    return 0;

}

char *string_in(const char *st1,const char *st2)
{
    int seek_length;
    int cmp_length=strlen(st2);                 //字符串需要比较的长度
    seek_length=strlen(st1)-cmp_length+1;       //至少搜寻的长度
    int nofind=1;

    while((nofind=strncmp(st1,st2,cmp_length))&&seek_length>0)//逐次递增st1的指针，直到比较发现到相同的字符串
    {                                                           //大于0这一点，要注意：小于零也是真，如果不检查seek_length大于零就有可能进入死循环
        seek_length--;
        st1++;
    }
    if(nofind)
        return NULL;
    else
        return (char *)st1;//这个警告就是怕你把这个指向const的指针赋给了一个普通指针
}                           //这个(char *)是在强制转换成普通指针吧
