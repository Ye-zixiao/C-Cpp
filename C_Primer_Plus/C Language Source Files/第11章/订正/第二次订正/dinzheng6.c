#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc,char *argv[])
{
    if(argc>2)
        puts("Enter the right form for this program:");
    else if(argc==2)
    {
        if(argv[1][0]!='-')
            puts("Enter the right form for this program");
        else
        {
            char ch;
            switch(argv[1][1])
            {
                case 'p':
                    while((ch=getchar())!=EOF)
                        putchar(ch);                //由于getchar的特性导致按下回车就输出
                    break;
                case 'u':
                    while((ch=getchar())!=EOF)
                        putchar(toupper(ch));
                    break;
                case 'l':
                    while((ch=getchar())!=EOF)
                        putchar(tolower(ch));
                        break;
                default:
                    puts("Enter the right form for this program");
                    break;
            }
        }
    }
    puts("Done");

    return 0;
}
