#include<stdio.h>
#define SIZE 81
void storechar(char *str,int n);

int main(void)
{
    char arr[SIZE];
    storechar(arr,SIZE);
    fputs(arr,stdout);

    return 0;
}

void storechar(char *str,int n)
{
    fgets(str,n,stdin);
}
