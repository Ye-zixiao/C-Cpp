#include<stdio.h>
double power(double x, int exp);

int main(void)
{
	double num1;
	int num2;

	printf("Enter two numbers for this program\n");
	printf("(enter q to quit)\n");
	while (scanf("%lf %d", &num1, &num2) == 2)
	{
		printf("%0.2f to the power %d is %0.2f\n", num1, num2, power(num1, num2));
		printf("Keep entering for this program\n");
		printf("(enter q to quit)\n");
	}
	printf("Done\n");

	return 0;
}

double power(double x, int exp)
{
	double ans = 1.0;

	if (exp == 0)
	{
		if (x == 0)
			printf("0 to the power 0 is undefined,but see 1 as the answer\n");
		ans = 1;
	}                                   /*注意：else if 语句是第一个if else语句里else的分支而不是if里的分支
											所以：if（）
													if（）    不能写成else if
												   else
													   if（）  这里的if可以变成else if
													   else                                                     */
	else if (exp > 0)//正次幂

		ans = x * power(x, --exp);
	else//负次幂
		ans = (1 / x) * power(x, ++exp);

	return ans;
}
