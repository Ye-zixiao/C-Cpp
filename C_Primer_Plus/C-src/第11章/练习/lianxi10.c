#include<stdio.h>
#include<string.h>
#define SIZE 81
#define SPACE ' '
void input_string(char *str);

int main(void)
{
    char input[SIZE];
    char *ptr=input;
    char ch;
    int ct=0;

    while((ch=getchar())!='\n'&&ct<=SIZE-2)
    {
        *ptr=ch;
        ptr++;
        ct++;
    }
    *ptr='\0';

    input_string(input);
    puts(input);

    return 0;

}

void input_string(char *str)
{
    char *temp;

    while(temp=strchr(str,SPACE))
    {
        str=strcat(str,temp);

    }
}
