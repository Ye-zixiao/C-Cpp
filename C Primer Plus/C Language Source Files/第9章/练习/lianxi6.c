#include<stdio.h>
void change(double *px,double *py,double *pz);

int main(void)
{
    double x=1.5,y=0.2,z=2.1;

    printf("Originally, x=%0.2f and y=%0.2f and z=%0.2f\n",x,y,z);
    change(&x,&y,&z);
    printf("Now,x=%0.2f and y=%0.2f and z=%0.2f\n",x,y,z);

    return 0;
}

void change(double *px,double *py,double *pz)
{
    double temp1,temp2,temp3;
    if(*px>*py)
    {
        temp1=*px;
        temp2=*py;
    }
    else
    {
        temp1=*py;
        temp2=*px;
    }
    if(temp1>*pz)
    {
        if(*pz>temp2)
        {
            temp3=temp2;
            temp2=*pz;
        }
        else
            temp3=*pz;
    }
    else
    {
        temp3=temp2;
        temp2=temp1;
        temp1=*pz;
    }

    *px=temp3;
    *py=temp2;
    *pz=temp1;
}
