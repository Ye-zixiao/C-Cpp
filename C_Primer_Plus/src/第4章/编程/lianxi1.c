#include<stdio.h>
int main(void)
{
    char f_name[10],l_name[10];

    printf("Enter your first name:");
    scanf("%s",f_name);
    printf("Enter your last name:");
    scanf("%s",l_name);
    printf("Your last name is %s,and your first name is %s.\n",l_name,f_name);

    return 0;
}
