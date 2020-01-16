#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#define STOP '|'
int main(void)
{
    char c;
    char prev;
    long n_chars=0L;
    int n_words=0;
    int n_lines=0;
    int p_lines=0;
    bool inword=false;

    printf("Enter text to analysis(| to quit this program).\n");
    prev='\n';

    while((c=getchar())!=STOP)
    {
        n_chars++;
        if(c=='\n')
            n_lines++;
        if(!isspace(c)&&!inword)//如果输入字符不是空白字符且单词标记还是0，那么这就是单词的开始
        {
            inword=true;        //置单词标记位为1
            n_words++;
        }
        if(isspace(c)&&inword)  //如果输入的字符是空白字符而且单词标记位是1，那么就是单词的结束
            inword=false;       //置单词位为0
        prev=c;                 //为的是记录退出之前的字符，看是否是‘\n’换行符
    }

    if(prev!='\n')//记录特殊行
        p_lines=1;
    printf("characters=%ld, words=%d,lines=%d,",
           n_chars,n_words,n_lines);
    printf("partial line=%d\n",p_lines);

    return 0;
}
