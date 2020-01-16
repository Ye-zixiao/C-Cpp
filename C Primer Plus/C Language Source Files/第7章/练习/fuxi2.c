#include<stdio.h>
int main(void)
{
    char ch;
    int lc=0;
    int uc=0;
    int oc=0;

    printf("Enter the words you want to say:\n");
    while((ch=getchar())!='#')
    {
        if(ch=='\n')
            continue;
        if(ch>='a'&&ch<='z')
            lc++;
        else if(ch>='A'&&ch<='Z')
            uc++;
        else
            oc++;
    }
    printf("lowercase=%d,uppercase=%d,others=%d.\n",lc,uc,oc);

    return 0;
}
