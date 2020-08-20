#include<stdio.h>
void copy_arr(int m,int n,double arr1[m][n],double arr2[m][n]);
void show_arr(int m,int n,double arr[m][n]);

int main(void)
{
    double arr1[3][5]={{3.5,3.1,2.1,5.1,1.2},
    {5.2,9.6,4.5,3.1,1.3},{5.1,6.6,4.4,2.2,1.4}};
    double arr2[3][5];
    printf("this is arr1:\n");
    show_arr(3,5,arr1);

    copy_arr(3,5,arr2,arr1);
    printf("this is arr2:\n");
    show_arr(3,5,arr2);

    return 0;
}

void copy_arr(int m,int n,double arr1[m][n],double arr2[m][n])
{
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            arr1[i][j]=arr2[i][j];
}

void show_arr(int m,int n,double arr[m][n])
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%0.1f ",arr[i][j]);
        putchar('\n');
    }
}
