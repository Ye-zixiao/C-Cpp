#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

int main(void)
{
    char ch;
    bool read_word=false;
    int up_num=0,low_num=0,word_num=0,punct_num=0,digit_num=0;
    while((ch=getchar())!=EOF)
    {
        if(ispunct(ch))
            punct_num++;
        else if(isdigit(ch))
            digit_num++;
        else if(islower(ch))
            low_num++;
        else if(isupper(ch))
            up_num++;
        if(!read_word&&isalpha(ch))             //如果检测到读取了一个字母，同时标志位表示之前不是字母，那么就增加单词数
        {
            read_word=true;
            word_num++;
        }
        if(read_word&&!isalpha(ch))            //如果检测到不是字母，同时标志位表示之前的字符是字母那么就将标志位变成false
            read_word=false;
    }
    printf("up_num=%d,low_num=%d,word_num=%d,punct_num=%d,digit_num=%d",
           up_num,low_num,word_num,punct_num,digit_num);

    return 0;
}
