#include<stdio.h>
#include<stdlib.h>
#include"fuzhu2.h"

int main(void)
{
    int mode;
    int pre_mode;
    double distance,fuel;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d",&mode);
    pre_mode=mode;
    while(mode>=0)
    {
        check_mode(&mode);
        if(mode==PRE_MODE)          //������ǰ��ģʽ
            mode=pre_mode;
        get_info(mode,&distance,&fuel);
        show_info(mode,distance,fuel);
        printf("Enter 0 for metric mode,1 for US mode");
        printf(" (-1 to quit )");
        pre_mode=mode;              //����ǰһ��ģʽ
        scanf("%d",&mode);
    }
    printf("Done.\n");

    return 0;
}
