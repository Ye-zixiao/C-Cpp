/*------printf()µÄ·µ»ØÖµ-------*/
#include <stdio.h>
int main(void)
{
    int bph2o=212;
    int rv;

    rv=printf("%d F is water's bolling point.\n",
              bph2o);
    printf("The printf() function printed %d character.\n",rv);

    return 0;
}
