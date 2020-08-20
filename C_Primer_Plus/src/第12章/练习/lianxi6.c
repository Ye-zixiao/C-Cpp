#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define QUANLITY 1000
#define RANGE 10

int rand_num(int num);

int main(void)
{
    int ct=1;

    while(ct++<=10)
    {
        int i;
        int ct_1=0;
        int ct_2=0;
        int ct_3=0;
        int ct_4=0;
        int ct_5=0;
        int ct_6=0;
        int ct_7=0;
        int ct_8=0;
        int ct_9=0;
        int ct_10=0;
        int seed;

        printf("Time %d:\n",ct-1);
        printf("Enter the seed: ");
        scanf("%d",&seed);
        srand(seed);
        for(i=0;i<QUANLITY;i++)
        {
            switch(rand_num(RANGE))
            {
                case 1:
                    ct_1++;
                    break;
                case 2:
                    ct_2++;
                    break;
                case 3:
                    ct_3++;
                    break;
                case 4:
                    ct_4++;
                    break;
                case 5:
                    ct_5++;
                    break;
                case 6:
                    ct_6++;
                    break;
                case 7:
                    ct_7++;
                    break;
                case 8:
                    ct_8++;
                    break;
                case 9:
                    ct_9++;
                    break;
                case 10:
                    ct_10++;
                    break;
                default:
                    break;
            }
        }
        printf("ct_1=%d,ct_2=%d,ct_3=%d,ct_4=%d,ct_5=%d,ct_6=%d,ct_7=%d,ct_8=%d,ct_9=%d,ct_10=%d\n",
               ct_1,ct_2,ct_3,ct_4,ct_5,ct_6,ct_7,ct_8,ct_9,ct_10);
    }
    puts("Done");

    return 0;
}

int rand_num(int num)
{
    int rand_number;
    rand_number=rand()%RANGE+1;

    return rand_number;
}
