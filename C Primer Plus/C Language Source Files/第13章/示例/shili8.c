#include<stdio.h>
#include<stdlib.h>
#define ARSIZE 1000

int main(void)
{
    double numbers[ARSIZE];
    double value;
    const char *file="numbers.dat";
    int i;
    long pos;
    FILE *iofile;

    for(i=0;i<ARSIZE;i++)
        numbers[i]=100.0*i+1.0/(i+1);

    if((iofile=fopen(file,"wb"))==NULL)                                 //以二进制写模式打开文件
    {
        fprintf(stderr,"Could not open %s for output.\n",file);
        exit(EXIT_FAILURE);
    }
    fwrite(numbers,sizeof(double),ARSIZE,iofile);                       //将数组中的数字写到iofile指向的文件
    fclose(iofile);                                                     //关闭文件指针所指向的文件
    if((iofile=fopen(file,"rb"))==NULL)                                 //以二进制读模式打开文件
    {
        fprintf(stderr,"Could not open %s for random access.\n",file);
        exit(EXIT_FAILURE);
    }

    printf("Enter an index in the range 0-%d.\n",ARSIZE-1);             //要求输入一个指数，用来指明文件中数据的位置
    while(scanf("%d",&i)==1&&i>=0&&i<ARSIZE)
    {
        pos=(long)i*sizeof(double);                                     //计算偏移量
        fseek(iofile,pos,SEEK_SET);                                     //文件指针指向以基准在偏移之后的位置
        fread(&value,sizeof(double),1,iofile);                          //从文件中偏移后指向的指针位置读取一个元素的数据到value中
        printf("The value there is %f.\n",value);
        printf("Next index (out of range to quit):\n");
    }

    fclose(iofile);
    puts("Bye!");

    return 0;
}
