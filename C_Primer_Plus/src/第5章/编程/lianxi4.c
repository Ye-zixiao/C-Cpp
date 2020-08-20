#include<stdio.h>
const float CM_INCH = 0.393701;
const int INCH_FEET = 12;

int main(void)
{
	float input_height, height_inch, inches;
	int feet;

	printf("Enter a height in centimeters:");
	scanf("%f", &input_height);
	while (input_height > 0)
	{
		height_inch = CM_INCH * input_height;
		feet = (int)height_inch / INCH_FEET;                //使用强制类型转化运算符计算英尺
		inches = height_inch - feet * INCH_FEET;             //计算剩余的英寸数

		printf("%.1f cm=%d feet,%0.1f inches.\n",input_height,feet,inches);
		printf("Enter a height in centimeters(<=0 to quit):");
		scanf("%f", &input_height);
	}
	printf("bye\n");

	return 0;
}
