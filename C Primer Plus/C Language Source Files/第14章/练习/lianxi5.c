#include<stdio.h>
#define LEN 20

struct name {
	char fname[LEN];
	char lname[LEN];
};

typedef struct {
	struct name member;
	float grade[3];
	float average;
}student;

void input_grade(student* arr, char* st, float grade1, float grade2, float grade3, int n);
void get_average(student* arr,int n);
void show_arrdata(student* arr,int n);

int main(void)
{
	student arr[4] = {
		{{"Hance","Lucky"}},
		{{"Jokies","Mary"}},
		{{"Unit","Bary"}},
		{{"Shower","Raty"}}
	};

	int i;
	for (i = 0; i < 4; i++)
	{
		float grade1, grade2, grade3;
		char st[LEN];

		printf("Enter name of student.\n");
		scanf("%s", st);
		printf("Enter the grades of the student: ");
		scanf("%f %f %f", &grade1, &grade2, &grade3);
		input_grade(arr, st, grade1, grade2, grade3, 4);
	}

	get_average(arr,4);
	show_arrdata(arr, 4);
	float sum = 0;
	for (i = 0; i < 4; i++)
		sum += arr[i].average;
	printf("The average grade of this class is %.2f\n", sum / 4);

	return 0;
}

void input_grade(student *arr,char* st, float grade1, float grade2, float grade3,int n)
{
	int i;
	int flag;

	for (i = 0; i < n; i++)
	{
		if ((flag = strcmp(st, arr[i].member.fname)) == 0)              //其实这道题没必要指定输入
			break;
	}
	if (flag == 0)
	{
		arr[i].grade[0] = grade1;
		arr[i].grade[1] = grade2;
		arr[i].grade[2] = grade3;
	}
	else
		printf("Error in inputing data.\n");
}

void get_average(student* arr,int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		float sum = 0.0;
		int j;

		for (j = 0; j < 3; j++)
			sum += arr[i].grade[j];
		arr[i].average = sum / 3;
	}
}

void show_arrdata(student* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s %s :grade1 %.2f ,grade2 %.2f ,grade3 %.2f ,and its average grade is %.2f\n",
			arr[i].member.fname, arr[i].member.lname, arr[i].grade[0], arr[i].grade[1], arr[i].grade[2], arr[i].average);
}
