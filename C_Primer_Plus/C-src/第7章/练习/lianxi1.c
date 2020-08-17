#include<stdio.h>
#define SPACE ' '
int main(void)
{
    char ch;
    int s_count=0,n_count=0,o_count=0,count=0;

    printf("Enter the words for this program:\n");
    while((ch=getchar())!='#')
    {
        count++;
        if(ch==SPACE)
            s_count++;
        else if(ch=='\n')
            n_count++;
        else
            o_count++;
    }
    printf("total=%d,space=%d,n_change=%d,others=%d\n",count,s_count,
           n_count,o_count);

    return 0;
}
