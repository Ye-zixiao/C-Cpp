/*------scanf()����ʾ-------*/
#include<stdio.h>
int main(void)
/*{
    char a,b,num[20];
    int rv;
    printf("Enter your aph:");
    scanf("%c",&a);                     //������ĵ�һ���ַ���ʼ��ȡ
    scanf(" %c",&b);                    //���������ո񣨰����ո��Ʊ�������з������ӵ�һ�������ַ���ʼ��ȡ
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
