#include<stdio.h>
double power(double, int);

int main(void)
{
	double x, xpow;
	int exp;

	printf("Enter a number and a integer power to which\n");
	printf("the number will be raised. Enter q to quit.\n");
	while (scanf("%lf %d", &x, &exp) == 2)
	{
		xpow = power(x, exp);
		printf("%0.3g  to the power %d is %0.5g\n", x, exp, xpow);
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Done\n");

	return 0;
}

double power(double x, int y)//可读性太差
{
	double ans = 1;
	int i;

	if (x == 0&&y!=0)
		ans = 0;
	else
	{
		if (y > 0)//正次幂
		{
			int i;                      //局部变量
			for (i = 1; i <= y; i++)
				ans *= x;
		}
		else if (y < 0)//负次幂
		{
			for (i = 1; i <= -y; i++)
				ans *= 1 / x;
		}
		else//0次幂
			ans = 1;
	}

	return ans;
}
