#include<stdio.h>
#include"name_st.h"

void get_names(names *person)
{
    printf("Please enter your first name: ");
    s_gets(person->first,SLEN);

    printf("Please enter your last name: ");
    s_gets(person->last,SLEN);

    status=1;
    //value=1;
}

void show_names(const names *person)
{
    printf("%s %s",person->first,person->last);
}

char *s_gets(char *st,int n)
{
    char *ret_val;
    char *find;

    ret_val=fgets(st,n,stdin);
    if(ret_val)
    {
        find=strchr(st,'\n');
        if(find)
            *find='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}
