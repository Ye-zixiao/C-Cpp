#include<stdio.h>
#include<string.h>
#define LEN 20

struct name {
	char fname[LEN];
	char mname[LEN];
	char lname[LEN];
};

typedef struct social {
	unsigned int num;
	struct name member;
}Vip;

void printvip(Vip* arr, int n);

int main(void)
{
	Vip arr[5] = {
		{302039823,"Flossie","Mary","Dribble"},
		{302139823,"Lucy","Jokes","Hance"},
		{302433122,"Shower","Mices","Honey"},
		{348934344,"Hunter","Mickes","Hamy"},
		{234343422,"Ferde","\0","Hoses"}
	};
	printvip(arr, 5);

	return 0;
}

void printvip(Vip* arr,int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (arr[i].member.lname[0] == '\0')
			printf("%s, %s --%u\n", arr[i].member.lname, arr[i].member.fname, arr[i].num);
		else
			printf("%s, %s %c --%u\n", arr[i].member.lname, arr[i].member.fname,
				arr[i].member.mname[0], arr[i].num);
	}
}
