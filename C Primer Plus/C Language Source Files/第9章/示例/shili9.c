#include<stdio.h>
void chat(int m,int n);

int main(void)
{
    int i,j;
    int hang;

    printf("Enter the rows(q to quit):\n");
    while(scanf("%d",&hang)==1)
    {
        if(hang>=26)
        {
            printf("That's too big\n");
            goto ju1;
        }

        for(i=1;i<=hang;i++)
        {
            for(j=1;j<=hang-i;j++)
                putchar(' ');
            chat(1,i);
            putchar('\n');
        }
        putchar('\n');
        ju1:printf("Enter the rows(q to quit):\n");
    }

    return 0;
}

void chat(int m,int n)              //m����ֵ��n��ӡ������ͬ����ĸ
{
    char ch='A'-1;

    putchar(ch+m);
    if(m<n)
        chat(m+1,n);
    if(m<n)                          //��m������n������ţ�ʱ�������ظ���ӡ����ַ�
        putchar(ch+m);
}
