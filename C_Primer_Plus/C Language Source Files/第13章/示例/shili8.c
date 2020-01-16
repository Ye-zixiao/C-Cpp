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

    if((iofile=fopen(file,"wb"))==NULL)                                 //�Զ�����дģʽ���ļ�
    {
        fprintf(stderr,"Could not open %s for output.\n",file);
        exit(EXIT_FAILURE);
    }
    fwrite(numbers,sizeof(double),ARSIZE,iofile);                       //�������е�����д��iofileָ����ļ�
    fclose(iofile);                                                     //�ر��ļ�ָ����ָ����ļ�
    if((iofile=fopen(file,"rb"))==NULL)                                 //�Զ����ƶ�ģʽ���ļ�
    {
        fprintf(stderr,"Could not open %s for random access.\n",file);
        exit(EXIT_FAILURE);
    }

    printf("Enter an index in the range 0-%d.\n",ARSIZE-1);             //Ҫ������һ��ָ��������ָ���ļ������ݵ�λ��
    while(scanf("%d",&i)==1&&i>=0&&i<ARSIZE)
    {
        pos=(long)i*sizeof(double);                                     //����ƫ����
        fseek(iofile,pos,SEEK_SET);                                     //�ļ�ָ��ָ���Ի�׼��ƫ��֮���λ��
        fread(&value,sizeof(double),1,iofile);                          //���ļ���ƫ�ƺ�ָ���ָ��λ�ö�ȡһ��Ԫ�ص����ݵ�value��
        printf("The value there is %f.\n",value);
        printf("Next index (out of range to quit):\n");
    }

    fclose(iofile);
    puts("Bye!");

    return 0;
}
