#include<stdio.h>
double cha(const double *arr,int n);

int main(void)
{
    double arr[]={5.1,6.2,3.1,9.2,5.1,3.0,5.2,3.7};
    double difference;

    difference=cha(arr,sizeof arr/sizeof arr[0]);
    printf("The difference between maxinum and mininum is %0.2f\n",difference);

    return 0;
}

double cha(const double *arr,int n)
{
    double max=*arr;
    double min=*arr;
    int i;
    for(i=1;i<n;i++)
    {
        max=max>*(arr+i)?max:*(arr+i);
        min=min<*(arr+i)?min:*(arr+i);
    }
    return max-min;
}
//与下面的判断语句其实没有什么区别都需要判断两次
/*
for(i=1;i<n;i++)
{
    if(max<arr[i])
        max=arr[i];
    else if(min>arr[i])
        min=arr[i];
}*/
