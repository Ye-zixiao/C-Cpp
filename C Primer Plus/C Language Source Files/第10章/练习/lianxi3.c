#include<stdio.h>
int maxinum(int *arr,int n);

int main(void)
{
    int arr[]={5,6,4,0,7,3,27,5,6,71};
    int max;
    max=maxinum(arr,sizeof arr/sizeof arr[0]);
    printf("The maxinum of this array is %d\n",max);

    return 0;
}

int maxinum(int *arr,int n)
{
    int max=*arr;
    int i;
    for(i=1;i<n;i++)
        max=max>*(arr+i)?max:*(arr+i);

    return max;
}
