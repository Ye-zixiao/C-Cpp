/*-------计算每百公里消耗的油量-----*/
#include <stdio.h>
int main(void)
{
	const float gallon_L = 3.785;
	const float miles_km = 1.609;
	float km, miles;
	float gallon, L;

	printf("Enter your miles:\n");
	scanf("%f", &miles);
	printf("Enter your gallon:\n");
	scanf("%f", &gallon);
	km = miles_km * miles;
	L = gallon * gallon_L;

	printf("Your miles per gallon=%.1f miles/gallon.\n", miles / gallon);
	printf("Your km per L=%.1f L/100km.\n", L / km*100.0f);

	return 0;
}
