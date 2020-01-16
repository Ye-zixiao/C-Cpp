//#include<stdio.h>
#define uint unsigned int
static unsigned long next=1;

uint rand0(void)
{
    next=next*1103515245+12345;
    return (uint)(next/65536)%32768;
}

void change_rand0(uint seed)
{
    next=seed;
}
