#include<stdio.h>
#define TWO 2
#define OW "Consistency is the last refuge of the \
unimaginative.-Oscar Wilde"

#define FOUR TWO*TWO
#define PX printf("X is %d.\n",x)
#define FMT "X is %d.\n"

#define SIX 2 * 3
#define SIX 3 * 3

int main(void)
{
    int x=TWO;

    PX;
    x=FOUR;
    printf(FMT,x);
    printf("%s\n",OW);
    printf("TWO: OW\n");

    printf("%d\n",SIX);

    return 0;
}
