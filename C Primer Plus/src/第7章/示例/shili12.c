#include<stdio.h>
#include<ctype.h>

int main(void)
{
    char ch;

    printf("Give me a letter of aphabet ,and I will give ");
    printf("an animal name\nbeginning with that letter.\n");
    printf("Please type in a letter;type # to end my act.\n");
    while((ch=getchar())!='#')
    {
        if('\n'==ch)
            continue;
        if(islower(ch))
            switch(ch)
        {
            case 'a':
                printf("argali\n");
                break;
            case 'b':
                printf("babirusa\n");
                break;
            case 'c':
                printf("coati\n");
                break;
            default:
                printf("That's a stumper!\n");
        }
        else
            printf("I recognize only lowercase letter.\n");
        while(getchar()!='\n')                  //��һ����ȫ��Ϊ����������ĸ�������ĸ�������P205��ֱ�����»س���ʱ���Ƴ�
            continue;
/*        while(getchar()!='\n')
            continue;*/
            //����û�����while������Ҳ��ȫ����
        printf("Please type another letter or a # .\n");
    }
    printf("Bye.\n");

    return 0;
}
