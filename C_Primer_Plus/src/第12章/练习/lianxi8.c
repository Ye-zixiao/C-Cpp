#include<stdio.h>
#include<stdlib.h>

int *make_array(int elem,int val);
void show_array(const int *arr,int n);

int main(void)
{
    int *pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while(scanf("%d",&size)==1&&size>0)
    {
        printf("Enter the initialization value: ");
        scanf("%d",&value);
        pa=make_array(size,value);
        if(pa)
        {
            show_array(pa,size);
            free(pa);                       //free()是非常必要的
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");

    return 0;
}

int *make_array(int elem,int val)
{
    int *re_pointer;
    int i;
    re_pointer=(int *)malloc(elem*sizeof(int));
    for(i=0;i<elem;i++)
        re_pointer[i]=val;
    return re_pointer;
}

void show_array(const int *arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%3d",arr[i]);
        if((i%(8-1)==0)&&i!=0)//换行符的代码可以稍微改进下
            putchar('\n');
    }
    if(i%(8-1)!=0)
        putchar('\n');
}

/*
可以改进成：
if(i%8==7)
    putchar('\n');
                        // 然后在末尾加上代码：
if(n%8!=0)
    putchar('\n');

                    */
