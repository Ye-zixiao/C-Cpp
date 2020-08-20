#include<stdio.h>
int main(void)
{
    char ch;
    int ei_count=0;
    _Bool e_flag=0;

    printf("Enter the converasation for this program.\n");
    while((ch=getchar())!='#')
    {
        if(ch=='e')
            e_flag=1;
        if(ch=='i'&&e_flag==1)
        {
            ei_count++;
            e_flag=0;
        }
    }
    printf("There are %d 'ei' in this converasation.\n",ei_count);

    return 0;
}
