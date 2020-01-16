#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
//char *s_gets(char *st,int n);

int main(void)
{
    char name[SIZE];
    FILE *fp;
    char ch;

    puts("Please enter the filename for this program: ");
    scanf("%s",name);
    if((fp=fopen(name,"r"))==NULL)
    {
        fprintf(stderr,"Wrong usage.\n");
        exit(EXIT_FAILURE);
    }
    //fprintf(stdout,"get here\n");
    while((ch=getc(fp))!=EOF)
        putc(ch,stdout);

    fclose(fp);
    return 0;
}

/*char *s_gets(char *st,int n)
{
    char *ret_val;
    int i;

    ret_val=fgets(st,n,stdin);
    if(ret_val)
    {
        while(st[i]!='\n'&&st[i]!='\0')
            continue;
        if(st[i]=='\n')
            st[i]='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}
*/
