#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

int main(void)
{
    char ch;
    bool read_word=false;
    int up_num=0;
    int low_num=0;
    int word_num=0;
    int punct_num=0;
    int digit_num=0;

    while((ch=getchar())!=EOF)
    {
        if(isdigit(ch))
            digit_num++;
        else if(ispunct(ch))
            punct_num++;
        else if(islower(ch))
            low_num++;
        else if(isupper(ch))
            up_num++;
        if(!read_word&&isalpha(ch))//注意这里不能写成else if因为else if是上面判断句的除此之外的条件
        {
            word_num++;
            printf("word_num=%d\n",word_num);
            read_word=true;
        }
        jif(read_word&&!isalpha(ch))
            read_word=false;
    }
    printf("up_num=%d,low_num=%d,digit_num=%d,punct_num=%d\n",
           up_num,low_num,digit_num,punct_num);
    printf("word_num=%d\n",word_num);

    return 0;
}
