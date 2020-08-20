#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RANGE 10
#define SIZE 100

int rand_num(int range);
void sort_arr(int *arr,int n);
void show_arr(const int *arr,int n);

int main(void)
{
    int *ptd;
    int i;

    ptd=(int *)malloc(SIZE*sizeof(int));
    srand((unsigned int)time(0));
    for(i=0;i<SIZE;i++)
        ptd[i]=rand_num(RANGE);
    printf("Initial array:\n");
    show_arr(ptd,SIZE);

    sort_arr(ptd,SIZE);
    printf("Array after the change:\n");
    show_arr(ptd,SIZE);

    free(ptd);                                  /*Very important!*/

    return 0;
}

int rand_num(int range)
{
    return rand()%range+1;
}

void sort_arr(int *arr,int n)
{
    int temp;
    int top,seek;

    for(top=0;top<n-1;top++)
        for(seek=top+1;seek<n;seek++)
            if(arr[top]<arr[seek])
            {
                temp=arr[top];
                arr[top]=arr[seek];
                arr[seek]=temp;
            }
}

void show_arr(const int *arr,int n)
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        printf("%3d",arr[i]);
        if(i%RANGE==9)
            putchar('\n');
    }
}
