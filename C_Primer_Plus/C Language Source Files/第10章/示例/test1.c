#include<stdio.h>
int main(void)
{
	const int arr[3] = { 0 };
	int * parr = &arr;			//��const���������ݵĵ�ַ��������ָͨ�룬���ǻ����ģ���ʹ�������������ͨ���ˣ�������һ�������
	*parr = 2;

	printf("arr[0]=%d\n", arr[0]);

	return 0;
}
