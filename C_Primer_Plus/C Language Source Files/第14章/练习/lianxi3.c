#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40

typedef struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	struct book* pNext;
}NODE,*PNODE;

char* s_gets(char* st, int n);
PNODE create_Linklist(int n);											//创建链表
void traverse_Linklist(PNODE pHead);									//遍历链表
void Empty_Linklist(PNODE pHead);										//释放链表的全部内存
int length_List(PNODE pHead);											//计算链表的长度
bool is_empty(PNODE pHead);												//判断链表是否为空
bool insert_Linklist(PNODE pHead, int pos);					//插入一个结点到链表当中
bool delete_Linklist(PNODE pHead, int pos);					//删除一个结点，并将返回值value用指针形式带回到主调函数当中
void sort_Linklist(PNODE pHead,int mode);										//利用选择排序法将链表进行升序排序

int main(void)
{
	PNODE pHead;
	pHead=create_Linklist(3);
	traverse_Linklist(pHead);

	sort_Linklist(pHead, 2);//以字母排序
	traverse_Linklist(pHead);
	sort_Linklist(pHead, 1);//以价格排序
	traverse_Linklist(pHead);

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			* find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

PNODE create_Linklist(int n)
{
	PNODE pHead,pTemp,p;
	pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
	{
		printf("Error in creating pHead.\n");
		exit(EXIT_FAILURE);
	}
	int i;
	pTemp = pHead;

	for (i = 0; i < n; i++)
	{
		p = (PNODE)malloc(sizeof(NODE));
		if (p == NULL)
		{
			printf("Error in creating new node.\n");
			exit(EXIT_FAILURE);
		}
		printf("Please enter the book title: ");
		s_gets(p->title, MAXTITL);
		printf("Now enter the author: ");
		s_gets(p->author, MAXAUTL);
		printf("Now enter the value: ");
		scanf("%f", &p->value);
		while (getchar() != '\n')
			continue;
		if (i < n - 1)
			printf("Enter the next book.\n");
		pTemp->pNext = p;
		pTemp = p;
	}
	pTemp->pNext = NULL;

	return pHead;
}

void traverse_Linklist(PNODE pHead)
{
	PNODE p = pHead->pNext;

	if (p != NULL)
		printf("Here is the list of yout books:\n");
	else
		printf("No books? Too bad.\n");
	while (p != NULL)
	{
		printf("%s by %s: $%.2f.\n", p->title, p->author, p->value);
		p = p->pNext;
	}
}

void Empty_Linklist(PNODE pHead)
{
	PNODE p = pHead;
	while (p != NULL)
	{
		PNODE q = p;
		p = p->pNext;
		free(q);
	}
}

int length_List(PNODE pHead)
{
	int len = 0;
	PNODE p = pHead->pNext;
	while (p != NULL)
	{
		len++;
		p = p->pNext;
	}
	return len;
}

bool is_empty(PNODE pHead)
{
	if (pHead->pNext == NULL)
		return true;
	else
		return false;
}

bool insert_Linklist(PNODE pHead, int pos)
{
	PNODE p=pHead;
	int j = 1;
	while (p != NULL && j < pos)
	{
		p = p->pNext;
		j++;
	}

	if (p == NULL || pos > j)
		return false;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		printf("Error in creating new node.\n");
		exit(EXIT_FAILURE);
	}
	printf("Please enter the book title: ");
	s_gets(pNew->title, MAXTITL);
	printf("Now enter the author: ");
	s_gets(pNew->author, MAXAUTL);
	printf("Now enter the value: ");
	scanf("%f", &pNew->value);
	while (getchar() != '\n')
		continue;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}

bool delete_Linklist(PNODE pHead, int pos)
{
	PNODE p = pHead;
	int j = 1;
	while (p->pNext != NULL && j < pos)
	{
		p = p->pNext;
		j++;
	}

	if (p->pNext == NULL || j > pos)
		return false;
	PNODE pd = p->pNext;
	p->pNext = pd->pNext;
	free(pd);
	return true;
}

void sort_Linklist(PNODE pHead,int mode)
{
	int i, j;
	PNODE p, q;
	int len = length_List(pHead);
	printf("len=%d\n", len);

	for(i=0,q=pHead->pNext;i<len-1;i++,q=q->pNext)
		for (j=i+1,p=q->pNext;j<len;j++,p=p->pNext)
		{
			if (mode == 1)
			{
				printf("get here 1.\n");
				if (q->value > p->value)
				{
					float vtemp = q->value;
					q->value = p->value;
					p->value = vtemp;

					char ttemp[MAXTITL];
					strcpy(ttemp, q->title);
					strcpy(q->title, p->title);
					strcpy(p->title, ttemp);

					char atemp[MAXAUTL];
					strcpy(atemp, q->author);
					strcpy(q->author, p->author);
					strcpy(p->author, atemp);
				}
			}
			if (mode == 2)
			{
				printf("get here 2\n");
				if (q->title[0] > p->title[0])
				{
					float vtemp = q->value;
					q->value = p->value;
					p->value = vtemp;

					char ttemp[MAXTITL];
					strcpy(ttemp, q->title);
					strcpy(q->title, p->title);
					strcpy(p->title, ttemp);

					char atemp[MAXAUTL];
					strcpy(atemp, q->author);
					strcpy(q->author, p->author);
					strcpy(p->author, atemp);
				}
			}
		}
}
