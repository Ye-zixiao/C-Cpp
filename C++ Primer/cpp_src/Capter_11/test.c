#include<stdio.h>

int main(void)
{
    int *pvalue=(int*)malloc(sizeof(int));
    *pvalue=100;
    printf("%d\n",*pvalue);
    free(pvalue);

    return 0;
}
