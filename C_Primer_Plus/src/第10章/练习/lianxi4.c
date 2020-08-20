#include<stdio.h>
int back_serial(const double *arr,int n);

int main(void)
{
    double arr[]={2.1,5.1,6.9,1.0,3.2,5.2,2.1,6.3};
    int serial;
    serial=back_serial(arr,sizeof arr/sizeof arr[0]);
    printf("The serial number of maxinum in this array is %d\n",
           serial);

    return 0;
}

int back_serial(const double *arr,int n)
{
    int i;
    double max=*arr;
    int serial=0;

    for(i=1;i<n;i++)
    {
        if(*(arr+i)>max)
        {
            max=*(arr+i);
            serial=i;               //¸Ä±äÐòºÅ
        }
    }

    return serial;
}
