#include<stdio.h>
void change(double *arr,int n);
void show_arr(const double *arr,int n);

int main(void)
{
    double arr[]={5.2,6.1,9.1,6.3,4.2,5.0};
    change(arr,sizeof arr/sizeof arr[0]);
    show_arr(arr,sizeof arr/sizeof arr[0]);

    return 0;
}

void change(double *arr,int n)
{
    double temp;
    int i;
    for(i=0;i<n/2;i++)
    {
        temp=*(arr+n-1-i);
        *(arr+n-1-i)=*(arr+i);
        *(arr+i)=temp;
    }
}

void show_arr(const double *arr,int n)
{
    int i;
    for( i=0;i<n;i++)
        printf("%0.1f ",arr[i]);
}
