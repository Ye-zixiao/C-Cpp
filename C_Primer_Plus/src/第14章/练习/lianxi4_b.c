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

void printvip(unsigned int num,struct name member);

int main(void)
{
	Vip arr[5] = {
		{302039823,"Flossie","Mary","Dribble"},
		{302139823,"Lucy","Jokes","Hance"},
		{302433122,"Shower","Mices","Honey"},
		{348934344,"Hunter","Mickes","Hamy"},
		{234343422,"Ferde","\0","Hoses"}
	};
	int i;
	for (i = 0; i < 5; i++)
		printvip(arr[i].num, arr[i].member);

	return 0;
}

void printvip(unsigned int num, struct name member)
{
	if (member.lname[0] == '\0')
		printf("%s, %s --%u\n", member.lname, member.fname, num);
	else
		printf("%s, %s %c --%u\n", member.lname, member.fname,
			member.mname[0], num);
}
