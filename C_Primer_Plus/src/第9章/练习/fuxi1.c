#include<stdio.h>
void menu1(void);
int get_number(int, int);

int main(void)
{
	int num;

	menu1();
	num = get_number(0, 4);
	printf("num=%d\n", num);

	return 0;
}

void menu1(void)										//�����˵�
{
	printf("Please choose one of the following:\n");
	printf("1) copy files            2) move files\n");
	printf("3) remove files          4) quit\n");
	printf("Enter the number of your choice:");
}

int get_number(int l_limit, int h_limit)				//��ȡһ�����Ϸ�Χ������
{
	int temp;
	char ch;
	int rv=0;

	while ((rv=scanf("%d", &temp))== 1 && (temp <l_limit || temp>h_limit))//�����˷�Χ
	{
		printf("%d is not right form to this program\n", temp);
		while (getchar() != '\n')				//�Ե�������ַ�
			continue;
		menu1();
		printf("\n");
		rv = 0;//�����������ֱ�ʶ��
	}
	if (rv!=1)//���������Ƿ������ַ�,����4��ͬʱ�Ե�������ַ�
	{
		while (getchar() != '\n')
			continue;
		return 4;
	}

	return temp;
}
