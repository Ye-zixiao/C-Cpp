/*------��ˮ����ˮ������-----*/
#include<stdio.h>
int main(void)
{
	double kuai_num,shui_num,dishu;
	dishu =3.156e-23;
	printf("dishu=%e\n", dishu);
	printf("Enter your kuai's num:");
	scanf("%lf",&kuai_num);

	shui_num =950.0*kuai_num/dishu;
	printf("%e\n",kuai_num);                                    //���Ҵ���ĵط���Ȼ��1�������uai_num���ӡ������ʾ��һ���ܴ����
	printf("zhongjianshu=%e.\n", 950.0 * kuai_num);
	printf("The number of your water-losing is:%e.\n",shui_num);//Ϊʲô���ó�float������ȷ�ģ��������ó�double�Ǿ��Ǵ���ģ�

	return 0;
}


/*{
    double a;
    scanf("%Lf",&a);                //��scanf��һ��double���������ֵҪ��ת��˵��%Lf������float��%f��
    printf("%e",a);

    return 0;
}*/
