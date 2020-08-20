/*------scanf()的演示-------*/
#include<stdio.h>
int main(void)
/*{
    char a,b,num[20];
    int rv;
    printf("Enter your aph:");
    scanf("%c",&a);                     //从输入的第一个字符开始读取
    scanf(" %c",&b);                    //会先跳过空格（包括空格、制表符、换行符），从第一个非零字符开始读取
    scanf("%s",num);
    rv=scanf("%s",num);
    printf("1.%c\n2.%c\n",a,b);
    printf("%d",rv);

    return 0;
}*/

{
    char num[20],yu[20];
    int rv;
    rv=scanf("%s %s",num,yu);
    printf("rv=%d\n",rv);
    printf("What you enter is the word :%s and %s.\n",num,yu);

    return 0;
}
