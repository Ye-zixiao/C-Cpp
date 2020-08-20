#include<stdio.h>
#include<stdlib.h>

struct flex
{
	int count;
	double average;
	double scores[];					//伸缩型数组成员
};

void showFlex(const struct flex* pst);

int main(void)
{
	struct flex* pf1, * pf2;
	int n = 5;
	int i;
	int tot = 0;

	pf1 = malloc(sizeof(struct flex) + n * sizeof(double));			//为结构体和伸缩型数组成员分配内存空间
	pf1->count = n;
	for (i = 0; i < n; i++)
	{
		pf1->scores[i] = 20.0 - i;
		tot += (int)pf1->scores[i];
	}
	pf1->average = tot / n;											//->运算符也可以称之为结构体解引用运算符
	showFlex(pf1);

	n = 9;
	tot = 0;
	pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
	pf2->count = n;
	for (i = 0; i < n; i++)
	{
		pf2->scores[i] = 20 - i / 2.0;
		tot += (int)pf2->scores[i];
	}
	pf2->average = tot / n;
	showFlex(pf2);

	free(pf1);														//释放动态内存空间
	free(pf2);
	return 0;
}

void showFlex(const struct flex* p)
{
	int i;
	printf("Scores : ");
	for (i = 0; i < p->count; i++)
		printf("%g ", p->scores[i]);
	printf("\nAverage: %g\n", p->average);
}
