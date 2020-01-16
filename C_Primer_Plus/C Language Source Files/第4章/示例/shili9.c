/*------ÑÝÊ¾×Ö·û´®¸ñÊ½------*/
#include<stdio.h>
#define RUD "Austin Justin"
void la(void);
int main(void)
{
    printf("[%2s]\n",RUD);
    printf("[%24s]\n",RUD);
    printf("[%24.5s]\n",RUD);
    printf("[%-24.5s]\n",RUD);
    la();

    return 0;
}

void la(void)
{
    char name[40];
    float cash=25.556;

    printf("Enter your name:");
    scanf("%s",name);

    printf("The %s family may be %g dollars richer.\n",name,cash);

}
