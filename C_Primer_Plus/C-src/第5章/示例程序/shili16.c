#include <stdio.h>
const int S_PER_M = 60;
const int S_PER_H = 3600;
const double M_PER_K = 0.62137;

int main(void)
{
	double dist_k, dist_m;                       //距离（公里）、距离（英里）
	double rate;                                 //速度
	int min, sec;                                //要求输入的跑步时间（分、秒）
	int time;                                    //总共跑了多少秒
	double mile_time;                            //跑一公里的时间
	int mile_min, mile_sec;                      //跑一公里的分、秒

	printf("This program converts your time for a metric race\n");
	printf("to a time for running a mile and to your average\n");
	printf("speed in miles per hour.\n");

	printf("Please enter the distance you run in kilometers.\n");
	scanf("%lf", &dist_k);						                            //对于一个double型的变量输入时需要%lf进行说明
	printf("Next,enter the time in minutes and seconds.\n");
	printf("Begin by entering the minutes.\n");
	scanf("%d", &min);
	printf("Now, enter the seconds.\n");
	scanf("%d", &sec);

	time = S_PER_M * min + sec;
	dist_m = dist_k * M_PER_K;

	rate = dist_m / time * S_PER_H;                             //求速度
	mile_time = (double)time / dist_m;                         //求跑一公里的时间
	mile_min = (int)mile_time / S_PER_M;                       //求跑一公里的时间（分）
	mile_sec = (int)mile_time % S_PER_M;                       //求跑一公里的时间（秒）

	printf("You run %1.2f km(%1.2f miles) in %dmin,%dsec.\n",
		dist_k, dist_m, min, sec);
	printf("That pace corresponds to running a mile in %dmin,", mile_min);
	printf("%d sec.\nAnd your average speed was %1.2f mph.\n", mile_sec,
		rate);

	return 0;
}
