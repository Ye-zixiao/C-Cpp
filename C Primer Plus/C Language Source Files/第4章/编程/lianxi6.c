#include<stdio.h>
#include<string.h>

int main(void)
{
    char f_name[10],l_name[10];

    printf("Enter your first name and your last name?\n");
    scanf("%s %s",f_name,l_name);
    printf("%s %s\n",f_name,l_name);
    printf("%*d %*d\n",strlen(f_name),strlen(f_name),
           strlen(l_name),strlen(l_name));

    printf("%s %s\n",f_name,l_name);
    printf("%-*d %-*d\n",strlen(f_name),strlen(f_name),
           strlen(l_name),strlen(l_name));

    return 0;
}
