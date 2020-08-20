#include<stdio.h>
int main(void)
//以上是求1+1/2+1/4。。。。。的前n项和
/*{
    int t_ct;
    double time,power_of_2;
    int limit;

    printf("Enter the number of terms you want: ");
    scanf("%d",&limit);
    for(time=0,power_of_2=1,t_ct=1;t_ct<=limit;
    t_ct++,power_of_2*=2.0)
    {
        time+=1.0/power_of_2;
        printf("time=%f when terms=%d.\n",time,t_ct);
    }

    return 0;
}*/


//计算1+1/2+1/3.。。。前n项和
{
    int count,fenmu;
    int num;//要计几项
    double sum;

    printf("Enter the number of counting that you want(enter number 0 to quit this system).\n");
    scanf("%d",&num);
    while(num>0)
    {
        for(fenmu=1,sum=0,count=1;count<=num;count++,fenmu++)
        {
            sum+=1.0/fenmu;
        }
        printf("When the counting-number=%d ,the sum=%f.\n",num,sum);
        printf("Keep entering the number of counting.\n");
        scanf("%d",&num);
    }
    printf("Done.\n");

    return 0;
}
