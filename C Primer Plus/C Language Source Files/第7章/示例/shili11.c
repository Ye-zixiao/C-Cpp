#include<stdio.h>
int main(void)
{
	double length, width;

	printf("Enter the length of rectangle:\n");
	while (scanf("%lf", &length) == 1)
	{
		printf("Enter the width of rectangle:\n");
		if (scanf("%lf", &width) != 1)					//ֻ���ڵ�����ڶ������ֵ�ʱ��������ĸ�����˳�
			break;                                      /*��������ô���ģ�������ʵ��ֻҪ����һ����ĸ��һѭ��������������ȥ*/
		printf("Width is %0.2f :\n", width);
		printf("Area is %0.2f :\n", width * length);
		printf("Enter the length of the rectangle:\n");
	}
	printf("Done!");

	return 0;
}
