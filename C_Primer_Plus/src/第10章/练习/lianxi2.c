#include<stdio.h>
void copy_arr(double *arr1,double *arr2,int n);
void copy_ptr(double *arr1,double *arr2,int n);
void copy_ptrs(double *arr1,double *start,double *end);
void show_arr(double *arr,int n);

int main(void)
{
    double source[5]={1.1,2.2,3.3,4.4,5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    show_arr(source,5);                     //展示原始数据
    putchar('\n');

    copy_arr(target1,source,5);
    show_arr(target1,5);                    //第一次复制打印
    putchar('\n');

    copy_ptr(target2,source,5);
    show_arr(target2,5);                    //第二次复制打印
    putchar('\n');

    copy_ptrs(target3,source,source+5);
    show_arr(target3,5);                    //第三次复制打印
    putchar('\n');

    return 0;
}

void copy_arr(double *arr1,double *arr2,int n)
{
    int i;
    for(i=0;i<n;i++)
        arr1[i]=arr2[i];
}

void copy_ptr(double *arr1,double *arr2,int n)
{
    int i;
    for(i=0;i<n;i++)
        (*arr1++)=(*arr2++);
}

void copy_ptrs(double *arr1,double *start,double *end)
{
    while(start<end)
    {
        *arr1=*start;
        start++;
        arr1++;
    }
}

void show_arr(double *arr,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%0.2f ",*(arr+i));
}
