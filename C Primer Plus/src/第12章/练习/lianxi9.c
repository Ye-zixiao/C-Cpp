#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define SIZE 10

int main(void)
{
    char (*ptd)[SIZE];
    int words_num;

    printf("How many words do you wish to enter? ");
    scanf("%d",&words_num);
    ptd=(char (*)[SIZE])malloc(words_num*SIZE*sizeof(char));//���䶯̬�ڴ�

    printf("Enter %d words now:\n",words_num);                //���뵥��
    int i,j;
    char ch;
    bool flag;
    for(i=0;i<words_num;i++)//���ַ�����ȱ�������Ҫ��ȡÿһ���ַ������ж�
    {
        j=0;
        flag=false;
        while(j<SIZE)
        {
            ch=getchar();
            if(!isalpha(ch)&&!flag)
                continue;
            flag=true;
            if(!isalpha(ch)&&flag)
                break;
            ptd[i][j]=ch;
            j++;
        }
        ptd[i][j]='\0';
    }

    printf("Here are your words:\n");
    for(i=0;i<words_num;i++)
        puts(ptd[i]);
    free(ptd);
    puts("Done.");

    return 0;
}
