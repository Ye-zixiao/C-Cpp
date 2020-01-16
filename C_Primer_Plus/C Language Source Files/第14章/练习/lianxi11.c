#include<stdio.h>
#include<math.h>

double (*fp[4])(double);
void transform(double* tar_arr, double* source_arr, int n, double(*fp)(double));
double mutilple_2(double x);
double differ_2(double x);
void show_arr(const double* arr, int n);

int main(void)
{
	fp[0] = sin;
	fp[1] = cos;
	fp[2] = mutilple_2;
	fp[3] = differ_2;
	double source_arr[10] = { 1.2,3.2,9.9,4.2,9.4,3.8,2.3,3.3,9.4,0.2 };
	double tar_arr[10];
	double* pst = tar_arr;

	//transform(tar_arr, source_arr, 10, (*fp[0]));
	//show_arr(tar_arr,10);

	//transform(tar_arr, source_arr, 10, (*fp[1]));
	//show_arr(tar_arr, 10);

	transform(pst, source_arr, 10, (*fp[2]));
	show_arr(tar_arr, 10);

	//transform(tar_arr, source_arr, 10, (*fp[3]));
	//show_arr(tar_arr,10);

	return 0;
}

void show_arr(const double* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%.2f ", arr[i]);
	putchar('\n');
}

double mutilple_2(double x)
{
	return x*2;
}

double differ_2(double x)
{
	return x - 2;
}

void transform(double* tar_arr, double* source_arr, int n, double(*fp)(double))
{
	int i;
	for (i = 0; i < n; i++)
	{
		//tar_arr[i] = 0;
		//printf("tar_arr[%d]=%.2f.\n", i, tar_arr[i]);
		double value = (*fp)(source_arr[i]);
		printf("value=%.2f\n", value);
		tar_arr[i] = value;
	}
}
