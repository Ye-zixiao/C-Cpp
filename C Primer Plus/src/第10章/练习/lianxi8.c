#include<stdio.h>
void copy_ptrs(double *start,double *arr2,double *end);
void show_arr(const double *arr,int n);

int main(void)
{
    double arr[7]={1.0,2.5,3.6,8.4,6.4,4.3,7.1};
    double arr1[3];
    printf("this is arr:\n");
    show_arr(arr,7);
    putchar('\n');

    copy_ptrs(arr1,arr+2,arr+5);
    printf("this is arr1:\n");
    show_arr(arr1,3);
    putchar('\n');

    return 0;
}

void copy_ptrs(double *arr1,double *start,double *end)//ʹ���˴��ݳ�ʼָ��ͽ���ָ��ķ���
{
    while(start<end)
    {
        *arr1=*start;
        arr1++;
        start++;
    }
}
//���µĲ���ʹ����ֱ�Ӵӿ�ʼ����ָ�벢�����˸�ֵ����
/*void copy_arr(int *arr1,const int *arr2,int n)
{
    int i;
    for(i=0;i<n;i++)
        arr1[i]=arr2[i];
}*/

void show_arr(const double *arr,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%0.1f ",*(arr+i));
}
