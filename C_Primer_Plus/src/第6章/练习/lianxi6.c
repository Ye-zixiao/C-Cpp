#include<stdio.h>
int sqr(int x);
int powr(int y);

int main(void)
{
    int l_lim,h_lim,hang;
    int i;

    printf("Enter the hign_limit:\n");
    scanf("%d",&h_lim);
    printf("Enter the low_limit:\n");
    scanf("%d",&l_lim);
    hang=h_lim-l_lim;

    printf("  n   n's squr   n's power\n");
    for(i=0;i<=hang;i++)
    {
        printf("%3d",l_lim+i);
        printf("%7d",sqr(l_lim+i));
        printf("%11d",powr(l_lim+i));
        printf("\n");
    }

    return 0;

}

int sqr(int x)
{
    return x*x;
}

int powr(int y)
{
    return y*y*y;
}
