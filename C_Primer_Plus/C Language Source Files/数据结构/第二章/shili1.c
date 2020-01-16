#include<stdio.h>
#include<time.h>
#include<math.h>

clock_t start, stop;
double duration;
#define MAXN 10
#define MAXK 1e7
double f1(int n, const double* arr, double x);
double f2(int n, const double* arr, double x);

int main(void)
{
	int i;
	double arr[MAXN];
	for (i = 0; i < MAXN; i++)
		arr[i] = (double)i;

	start = clock();
	for (i = 0; i < MAXK; i++)
		f1(MAXN, arr, 1.1);
	stop=clock();
	duration = ((double)(stop - start)) / CLK_TCK/MAXK;
	printf("ticks1=%f\n", (double)(stop - start));
	printf("duration =%6.2e\n", duration);

	start = clock();
	for (i = 0; i < MAXK; i++)
		f2(MAXN, arr, 1.1);
	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK / MAXK;
	printf("ticks1=%f\n", (double)(stop - start));
	printf("duration =%6.2e\n", duration);

	return 0;
}

double f1(int n, const double* arr, double x)
{
	int i;
	double p = 0;
	for (i = 0; i < n; i++)
		p += arr[i] * pow(x, i);
	return p;
}

double f2(int n,const double* arr, double x)//Ëã·¨¸üÓÅ
{
	int i;
	double p = arr[n - 1];
	for (i = n-1; i > 0; i--)
		p = arr[i - 1] + x * p;

	return p;
}
