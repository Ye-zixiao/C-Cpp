#include <stdio.h>
#include<string.h>
int main(void)
{
    char f_name[10],l_name[10];
    int f_namewidth,l_namewidth;
    printf("Enter your full name:");
    scanf("%s %s",f_name,l_name);
    f_namewidth=strlen(f_name);
    l_namewidth=strlen(l_name);

    printf("Your name is \"%s %s\",as you said.\n",f_name,l_name);
    printf("It can print as:%20s%20s.\n",f_name,l_name);
    printf("It can print as:%-20s%-20s.\n",f_name,l_name);
    printf("It can print as:%*s%*s.\n",f_namewidth+3,f_name,l_namewidth+3,l_name);

    return 0;
}
