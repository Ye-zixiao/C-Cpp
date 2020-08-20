/*------脱水计算水分子数-----*/
#include<stdio.h>
int main(void)
{
	double kuai_num,shui_num,dishu;
	dishu =3.156e-23;
	printf("dishu=%e\n", dishu);
	printf("Enter your kuai's num:");
	scanf("%lf",&kuai_num);

	shui_num =950.0*kuai_num/dishu;
	printf("%e\n",kuai_num);                                    //而且错误的地方竟然是1，输入给uai_num后打印它会显示成一个很大的数
	printf("zhongjianshu=%e.\n", 950.0 * kuai_num);
	printf("The number of your water-losing is:%e.\n",shui_num);//为什么设置成float就是正确的？而当设置成double是就是错误的？

	return 0;
}


/*{
    double a;
    scanf("%Lf",&a);                //用scanf对一个double浮点变量赋值要用转换说明%Lf；对于float用%f。
    printf("%e",a);

    return 0;
}*/
