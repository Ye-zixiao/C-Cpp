#include<stdio.h>
int main(void)
{
    _Bool isprime;
    int num,i,j;
    int count=0;

    printf("Please enter the number for this program\n");
    printf("Enter q to quit this program\n");
    while(scanf("%d",&num)==1)
    {
        if(num<=0)
            continue;
        for(i=2;i<=num;i++)
        {
            for(j=2,isprime=1;j*j<=i;j++)
            {
                if(i%j==0)          //�ҵ�һ������������ѭ��
                {
                    isprime=0;
                    break;
                }
            }

            if(isprime)             //����������ʹ�ӡ
            {
                printf("%4d",i);
                count++;
                if(count==8)       //ÿ�д�ӡ8��
                {
                    putchar('\n');
                    count=0;
                }
            }
        }
        printf("\n");
        printf("Enter next number for this program\n");
    }
    printf("Done\n");

    return 0;
}
