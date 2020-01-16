#include<stdio.h>
int main(void)
{
    float file_B,bps;
    printf("How much big of your file in MB?And how fast of your bps?\n");
    scanf("%g %g",&file_B,&bps);

    printf("At %0.2f megebits per second,a file of %0.2f megabytes\n",bps,file_B);
    printf("downloads in %0.2f seconds.\n",file_B*8/bps);
    return 0;
}
