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

char* string_in(char* st1, const char* st2)//ȱ�㣺�����е㸴��
{
	char* find = NULL;
	char* temp = st1;//ע�⣺ָ��const��ָ�븳����ָͨ�룬���о���C4090����Ϊ������������ָͨ���޸�const����

	while (temp = strchr(temp, *st2))               //����st1�ַ����������st2�ĵ�һ���ַ�������ҵ��ͽ���ѭ����
	{
		int ct = 0;
		while (*(temp + ct) == *(st2 + ct) && *(st2 + ct) != '\0')//����ctȥ����ָ��ͬʱҲ������temp�����ַ����������ַȷʵ�ǿ�ͷ�ǾͿ��Է���
			ct++;                                           //���st2+ct��ָ����������Ŀ��ַ�ʱ��û���ҵ���һ���ģ���ô��ʱ������������Ϊ��һ��������

		if (*(st2 + ct) == '\0')          //st2�������һ���򷵻�ָ��temp
		{
			find = temp;
			break;
		}
		else                                //�������Ϊ��һ����������ô�ٴ������һ���ĵط�������
		{
			temp += ct;
			continue;
		}
	}

	return find;
}
