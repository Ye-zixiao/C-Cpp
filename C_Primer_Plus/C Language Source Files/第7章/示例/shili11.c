#include<stdio.h>
int main(void)
{
	double length, width;

	printf("Enter the length of rectangle:\n");
	while (scanf("%lf", &length) == 1)
	{
		printf("Enter the width of rectangle:\n");
		if (scanf("%lf", &width) != 1)					//只能在当输入第二个数字的时候输入字母才能退出
			break;                                      /*理论是这么讲的，但是事实上只要输入一个字母第一循环程序它都进不去*/
		printf("Width is %0.2f :\n", width);
		printf("Area is %0.2f :\n", width * length);
		printf("Enter the length of the rectangle:\n");
	}
	printf("Done!");

	return 0;
}
