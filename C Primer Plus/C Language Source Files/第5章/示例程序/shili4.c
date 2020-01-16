#include<stdio.h>
int main(void)
/*{
    int dozen=12;
    dozen+=12;
    printf("%d",dozen);

    return 0;
}
*/

{
    int num=1;

    while(num<12)
    {
        printf("%4d %6d\n",num,num*num);
        num++;
    }

    return 0;
}
