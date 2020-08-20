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
        if(!read_word&&isalpha(ch))             //�����⵽��ȡ��һ����ĸ��ͬʱ��־λ��ʾ֮ǰ������ĸ����ô�����ӵ�����
        {
            read_word=true;
            word_num++;
        }
        if(read_word&&!isalpha(ch))            //�����⵽������ĸ��ͬʱ��־λ��ʾ֮ǰ���ַ�����ĸ��ô�ͽ���־λ���false
            read_word=false;
    }
    printf("up_num=%d,low_num=%d,word_num=%d,punct_num=%d,digit_num=%d",
           up_num,low_num,word_num,punct_num,digit_num);

    return 0;
}
