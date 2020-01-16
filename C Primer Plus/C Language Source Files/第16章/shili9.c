#include<stdio.h>

#define MYTYPE(X) _Generic((X),\
                           int:"int",\
                           float:"float",\
                           double:"double",\
                           default:"other"\
)
inline static eatline(void)
{
    while(getchar()!='\n')
        continue;
}

int main(void)
{
    int d=5;

    printf("%s\n",MYTYPE(d));
    printf("%s\n",MYTYPE(2.0*d));
    printf("%s\n",MYTYPE(3L));
    printf("%s\n",MYTYPE(&d));

    scanf("%d",&d);
    eatline();
    return 0;
}
