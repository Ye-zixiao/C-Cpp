#include<stdio.h>
#define FUNDLEN 50
#define N 2

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds* money, int n);

int main(void)
{
	struct funds jones[N] = {
		{
			"Garlic-Melon Bank",
			4032.27,
			"Lucky's Savings and Loan",
			8543.94
		},
		{
			"Honest Jack's Bank",
			3620.88,
			"Party Time Savings",
			3802.91
		}
	};

	printf("The Joneses have a total of $%.2f.\n", sum(jones, N));

	return 0;
}

double sum(const struct funds* money, int n)
{
	double total = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		//total += (money + i)->bankfund + (money + i)->savefund;					//使用结构体解引用运算符获得结构的成员数据
		//total += (*(money + i)).bankfund + (*(money + i)).savefund;				//使用普通指针解引用运算符后，再用点运算符获得结构成员的数据
		total += money[i].bankfund + money[i].savefund;								//使用数组形式的点运算符直接获得结构体成员数据
	}

	return total;
}
