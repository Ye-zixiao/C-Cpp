#include<stdio.h>
int main(void)
{
    int i=1;
    float n;
    printf("Watch out!Here come a bunch of fractions!\n");
    while(i++<30)
    {
        n=(float)1/i;
        printf("%.3f\n",n);
    }
    printf("That's all.folk!\n");

    return 0;

}
