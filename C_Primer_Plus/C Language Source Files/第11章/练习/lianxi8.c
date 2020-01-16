#include<stdio.h>
#include<string.h>
char* string_in(char* st1, const char* st2);

int main(void)
{
	char* find = NULL;
	find = string_in("haats", "at");
	if (find)
		puts("I find.");
	else
		puts("I didn't find.");

	return 0;
}

char* string_in(char* st1, const char* st2)//缺点：程序有点复杂
{
	char* find = NULL;
	char* temp = st1;//注意：指向const的指针赋给普通指针，会有警告C4090：因为这样可以让普通指针修改const数据

	while (temp = strchr(temp, *st2))               //先在st1字符串上面查找st2的第一个字符，如果找到就进入循环体
	{
		int ct = 0;
		while (*(temp + ct) == *(st2 + ct) && *(st2 + ct) != '\0')//利用ct去递增指针同时也保留好temp这个地址，如果这个地址确实是开头那就可以返回
			ct++;                                           //如果st2+ct的指针递增到最后的空字符时还没有找到不一样的，那么此时跳出，或者因为不一样而跳出

		if (*(st2 + ct) == '\0')          //st2增到最后还一样则返回指针temp
		{
			find = temp;
			break;
		}
		else                                //如果是因为不一样跳出，那么再从这个不一样的地方继续找
		{
			temp += ct;
			continue;
		}
	}

	return find;
}
