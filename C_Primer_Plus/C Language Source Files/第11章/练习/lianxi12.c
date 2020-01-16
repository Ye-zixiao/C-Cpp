#include<stdio.h>
#include<ctype.h>
#define SIZE 81
#define LIM 20
char *s_gets(char *st,int n);

int main(void)
{
    char input[LIM][SIZE];
	char* ptr[LIM];
	int ct = 0;
	puts("Enter the strings for this program:");
	while (s_gets(input[ct], SIZE) != NULL && ct < LIM && input[ct][0] != EOF)
	{
		ptr[ct] = input[ct];
		ct++;
	}

	int i,j;
	int da_num=0,xiao_num=0,word_num=0,punct_num=0,digit_num=0;

	for(i=0;i<ct;i++)
    {
        j=0;
        while(ptr[i][j]!='\0')
        {
            if(isupper(ptr[i][j]))
                da_num++;
            else if(islower(ptr[i][j]))
                xiao_num++;
            else if(ispunct(ptr[i][j]))
                punct_num++;
            else if(isdigit(ptr[i][j]))
                digit_num++;
            j++;
        }
    }
    for(i=0;i<ct;i++)
    {
        j=0;
        while(ptr[i][j]!='\0')
        {
            if(isspace(ptr[i][j])||isdigit(ptr[i][j])||ispunct(ptr[i][j]))//判断是否为字母，若不是继续读取
            {
                j++;
                continue;
            }
            while(isalpha(ptr[i][j]))                       //如果是字母等它读完字母读到非字母后加一
            {
                j++;
            }
            word_num++;
            j++;
        }
    }
    printf("da_num=%d,xiao_num=%d,word_num=%d,punct_num=%d,digit_num=%d\n",
           da_num,xiao_num,word_num,punct_num,digit_num);

    return 0;
}

char *s_gets(char *st,int n)
{
    char *ret_val;

    ret_val=fgets(st,SIZE,stdin);
    if(ret_val)
    {
        while(*st!='\0'&&*st!='\n')
            st++;
        if(*st=='\n')
            *st='\0';
        else
            while(getchar()!='\n')
            continue;
    }

    return ret_val;
}
