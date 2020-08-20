#include <stdio.h>
const int S_PER_M = 60;
const int S_PER_H = 3600;
const double M_PER_K = 0.62137;

int main(void)
{
	double dist_k, dist_m;                       //���루��������루Ӣ�
	double rate;                                 //�ٶ�
	int min, sec;                                //Ҫ��������ܲ�ʱ�䣨�֡��룩
	int time;                                    //�ܹ����˶�����
	double mile_time;                            //��һ�����ʱ��
	int mile_min, mile_sec;                      //��һ����ķ֡���

	printf("This program converts your time for a metric race\n");
	printf("to a time for running a mile and to your average\n");
	printf("speed in miles per hour.\n");

	printf("Please enter the distance you run in kilometers.\n");
	scanf("%lf", &dist_k);						                            //����һ��double�͵ı�������ʱ��Ҫ%lf����˵��
	printf("Next,enter the time in minutes and seconds.\n");
	printf("Begin by entering the minutes.\n");
	scanf("%d", &min);
	printf("Now, enter the seconds.\n");
	scanf("%d", &sec);

	time = S_PER_M * min + sec;
	dist_m = dist_k * M_PER_K;

	rate = dist_m / time * S_PER_H;                             //���ٶ�
	mile_time = (double)time / dist_m;                         //����һ�����ʱ��
	mile_min = (int)mile_time / S_PER_M;                       //����һ�����ʱ�䣨�֣�
	mile_sec = (int)mile_time % S_PER_M;                       //����һ�����ʱ�䣨�룩

	printf("You run %1.2f km(%1.2f miles) in %dmin,%dsec.\n",
		dist_k, dist_m, min, sec);
	printf("That pace corresponds to running a mile in %dmin,", mile_min);
	printf("%d sec.\nAnd your average speed was %1.2f mph.\n", mile_sec,
		rate);

	return 0;
}
