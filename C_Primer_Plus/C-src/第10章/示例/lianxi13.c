#include<stdio.h>
#define COLS 5
void get_data(double (*arr)[COLS],int n);
double rows_average(const double *arr,int n);
double average_all(const double (*arr)[COLS],int n);
double maxinum(const double (*arr)[COLS],int n);

int main(void)
{
    double arr[3][COLS];
    printf("Please enter the data for this program:\n");
    get_data(arr,3);//ÊäÈë15¸öÊý
    printf("The array you input as follows:\n");
    show_arr(arr,3);

    printf("From the data you input,we can analyze:\n");
    int i;
    for(i=0;i<3;i++)
        printf("The average of row %d is %0.2f\n",i,rows_average(arr[i],COLS));

    printf("The average of all data is %0.2f\n",average_all(arr,3));
    printf("The maxinum of all data is %0.2f\n",maxinum(arr,3));

    return 0;

}

void get_data(double (*arr)[COLS],int n)
{
    int i,j;

    for(i=0;i<n;i++)
        for(j=0;j<COLS;j++)
            scanf("%lf",&arr[i][j]);
}

double rows_average(const double *arr,int n)
{
    int i;
    double subtot=0;

    for(i=0;i<n;i++)
        subtot+=arr[i];

    return subtot/COLS;
}

double average_all(const double (*arr)[COLS],int n)
{
    int i,j;
    double total=0;

    for(i=0;i<n;i++)
        for(j=0;j<COLS;j++)
            total+=arr[i][j];

    return total/(COLS*n);
}

double maxinum(const double (*arr)[COLS],int n)
{
    double max=0;
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<COLS;j++)
            max=max>arr[i][j]?max:arr[i][j];
    }

    return max;
}

void show_arr(const double (*arr)[COLS],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<COLS;j++)
            printf("%0.2f ",arr[i][j]);
        putchar('\n');
    }
}
