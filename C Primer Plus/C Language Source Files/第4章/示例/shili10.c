/*------一些不匹配的整型转换----*/
#include<stdio.h>
#define PAGES 336
#define WORDS 65618
int main(void)
{
    short num=PAGES;
    short mnum=-PAGES;

    printf("num as short and unsigned short: %hd %hu\n",num,num);
    printf("-num as short and unsigned short: %hd %hu\n",mnum,mnum);//第一个溢出，第二个数据类型不匹配
    printf("num as int and char:%d %c\n",num,num);//第一个正常，但是第二个溢出后转换成字符
    printf("WORDS as int ,short,and char:%d %hd %c\n",WORDS,WORDS,WORDS);//第一个正常，第二个溢出，第三个溢出后转换成字符

    return 0;
}
