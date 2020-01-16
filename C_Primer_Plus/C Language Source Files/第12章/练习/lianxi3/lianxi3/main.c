#include<stdio.h>
#include"pe12_3a.h"

int main(void)
{
    int mode;
    double result;

    printf("Enter 0 for metric mode,1 for US mode: ");
    scanf("%d",&mode);
    while(mode>=0)
    {
        result=get_info(mode);
        show_info(result,mode);
        printf("Enter 0 for metric mode,1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d",&mode);
    }
    printf("Done.\n");
    return 0;
}
