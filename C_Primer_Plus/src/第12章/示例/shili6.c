#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int static_store=30;
const char *pcg="String Literal";

int main(void)
{
    int auto_store=40;
    char auto_string[]="Auto char Array";
    int *pi;
    char *pcl;

    pi=(int *)malloc(sizeof(int));
    *pi=35;
    pcl=(char *)malloc(strlen("Dynamic String")+1);
    strcpy(pcl,"Dynamic String");

    printf("static_storeȫ�ֱ���: %d at %p\n",static_store,&static_store);//��̬�ڴ�
    printf("auto_store�Զ�����: %d at %p\n",auto_store,&auto_store);      //�Զ��洢
    printf("*pi��̬�ڴ�: %d at %p\n",*pi,pi);                             //��̬�ڴ�
    printf("%sȫ�ֱ��� at %p\n",pcg,pcg);                                 //��̬�ڴ�
    printf("%s�Զ����� at %p\n",auto_string,auto_string);                 //�Զ��洢
    printf("%s��̬�ڴ� at %p\n",pcl,pcl);                                 //��̬�ڴ�
    printf("%s�ַ����� at %p\n","Quoted String","Quoted String");         //�Զ��洢

    free(pi);
    free(pcl);
    return 0;
}
/*
volatile Ӱ�����������Ľ��,ָ����volatile ��������ʱ���ܷ����仯�ģ�
��volatile�����йص����㣬��Ҫ���б����Ż������������VC++ �ڲ���release
���ִ����ʱ����б����Ż�����volatile�ؼ��ֵı����йص����㣬�������б����Ż�������
���磺
volatile int i=10;
int j = i;
...
int k = i;
volatile ���߱�����i����ʱ���ܷ����仯�ģ�ÿ��ʹ������ʱ������i�ĵ�ַ�ж�ȡ��
������������ɵĿ�ִ��������´�i�ĵ�ַ��ȡ���ݷ���k�С�
�� �Ż������ǣ����ڱ������������δ�i�����ݵĴ���֮��Ĵ���û�ж�i���й�������
�����Զ����ϴζ������ݷ���k�С����������´�i�����������������
��� i��һ���Ĵ����������߱�ʾһ���˿����ݾ����׳�������˵volatile���Ա�֤�������ַ���ȶ����ʣ�
�������*/
