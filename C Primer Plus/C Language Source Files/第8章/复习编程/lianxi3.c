#include<stdio.h>
#include<ctype.h>

int main(void)
{
	int low_ct = 0, up_ct = 0,other_ct=0;
	char ch;

	printf("Enter the chars you want\n");
	while ((ch = getchar()) != EOF)
	{
		if (isupper(ch))
			up_ct++;
		else if (islower(ch))
			low_ct++;
		else
			other_ct++;
	}
	printf("There are %d uppercase aphabet,%d lower_case aphabet,and %d others.\n",
		up_ct, low_ct, other_ct);

	return 0;
}
