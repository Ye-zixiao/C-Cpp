#include<stdio.h>
#include"name_st.h"
#include"name_st.h"

int status=0;
const int value=0;//const ����ֻ�����ļ��������ڲ����ӵ�����

int main(void)
{
    names candidate;

    get_names(&candidate);
    printf("Let's welcome ");
    show_names(&candidate);
    printf(" to this program.\n");

    printf("status=%d now.\n",status);
    return 0;
}
