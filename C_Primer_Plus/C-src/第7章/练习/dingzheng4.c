#include<stdio.h>
int main(void)
{
	double temp;
	double moss_weight = 0;			//�˵�����
	double beet_weight = 0;
	double carrot_weight = 0;
	double total_weight = 0;

	double moss_price = 0;			//�˵��ܼ�
	double beet_price = 0;
	double carrot_price = 0;
	double total_price = 0;

	char ch;

	double discount = 0;
	double trans_price = 0;

	printf("Choice the vegetable you want:\n");
	printf("a) moss             b) beet\n");
	printf("c) carrot           d) quit\n");
	while ((ch = getchar()) != 'd')
	{
		/*��ô��������ĸ��������������*/
		if (ch == '\n')					//��Իس������Ļ��з�������continue�����ע���������ֻ�������ĸ�����жϣ�
			continue;
		while (getchar() != '\n')		//������������ĸ�����ʹ�ò���ѭ��ȥ�Ե���ֻ��������ĸ��ֱ���������з�
			continue;
		switch (ch)
		{
			case 'a':
				printf("Enter the weight of moss\n");
				scanf_s("%lf", &temp);
				moss_weight += temp;
				total_weight += temp;
				moss_price += 2.05 * temp;
				total_price += 2.05 * temp;
				break;
			case 'b':
				printf("Enter the weight of beet\n");
				scanf_s("%lf", &temp);
				beet_weight += temp;
				total_weight += temp;
				beet_price += 1.15 * temp;
				total_price += 1.15 * temp;
				break;
			case 'c':
				printf("Enter the weight of carrot\n");
				scanf_s("%lf", &temp);
				carrot_weight += temp;
				total_weight += temp;					//������
				carrot_price += 1.09 * temp;
				total_price += 1.09 * temp;				//�ܼ�
				break;
			default:
				printf("Enter the right form\n");

		}
		printf("Please choice again\n");
	}

	if (total_weight <= 5)					//�����˷�
		trans_price = 6.5;
	else if (total_weight <= 20)
		trans_price = 14.0;
	else
		trans_price = 0.5 * (total_weight - 20) + 14;

	printf("Moss weight:%0.2f pound(s) ,single-price=$2.05/pound ,so moss price=%0.2f\n",
		moss_weight, moss_price);
	printf("Beet weight:%0.f pound(s) ,single-price=$1.15/pound ,so beet price=%0.2f\n",
		beet_weight, beet_price);
	printf("Carrot weight:%0.2f pound(s) ,single-price=$1.09/pound ,so carrot price=%0.2f\n",
		carrot_weight, carrot_price);
	printf("total price=%0.2f\n", total_price);
	if (total_price > 100.0)				//�����ۿ�
	{
		discount = total_price * 0.05;
		printf("discount=%0.2f\n", discount);
	}
	printf("transportation price =%0.2f\n", trans_price);
	printf("final price =%0.2f\n", total_price + trans_price - discount);

	return 0;
}
