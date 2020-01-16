#include<stdio.h>

void get_data(int m,int n,double arr[m][n]);
double rows_average(int m,const double arr[m]);
double average_all(int m,int n,const double arr[m][n]);
double maxinum(int m,int n,const double arr[m][n]);
void show_arr(int m,int n,const double arr[m][n]);

int main(void)
{
    double arr[3][5];
    printf("Please enter the data for this program:\n");
    get_data(3,5,arr);//当然了这里传输底层数组也是可以的，当时这样的话需要循环3次
    printf("The array you input as follows:\n");
    show_arr(3,5,arr);

    printf("From the data you input,we can analyze:\n");
    int i;
    for(i=0;i<3;i++)
        printf("The average of row %d is %0.2f\n",i,rows_average(5,arr[i]));

    printf("The average of all data is %0.2f\n",average_all(3,5,arr));
    printf("The maxinum of all data is %0.2f\n",maxinum(3,5,arr));

    return 0;
}

void get_data(int m,int n,double arr[m][n])
{
    int i,j;

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%lf",&arr[i][j]);
}

double rows_average(int m,const double arr[m])
{
    int i;
    double subtot=0;

    for(i=0;i<m;i++)
        subtot+=arr[i];

    return subtot/m;
}

double average_all(int m,int n,const double arr[m][n])
{
    int i,j;
    double total=0;

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            total+=arr[i][j];

    return total/(m*n);
}

double maxinum(int m,int n,const double arr[m][n])
{
    double max=0;
    int i,j;

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            max=max>arr[i][j]?max:arr[i][j];

    return max;
}

void show_arr(int m,int n,const double arr[m][n])
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%0.2f ",arr[i][j]);
        putchar('\n');
    }
}
