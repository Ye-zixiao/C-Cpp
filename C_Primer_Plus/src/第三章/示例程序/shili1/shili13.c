/*------��ʾһЩ���������е��������-------*/
#include<stdio.h>
int main(void)
//���������
/*{
    unsigned short a;
    short b;
    a=65535;
    b=32767;
    printf("%hu %hu %hu\n%hd %hd %hd\n",a,a+1,a+2,b,b+1,b+2);

    return 0;
}*/

//�����������
/*{
    float a;
    a=3.4e38*100.0f;

    printf("%e\n",a);

    return 0;
}*/

//�����������
{
	float a = 1.17549e-38;
	printf("%e\n", a/2);
	return 0;
}
