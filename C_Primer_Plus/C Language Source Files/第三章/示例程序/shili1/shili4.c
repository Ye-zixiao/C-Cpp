/*----------��ʾ��δ�ӡlong��short��unsigned long��Щ��������---------*/
int main(void)
{
    unsigned int un=3000000000;
    short end=200;
    long big=65537;
    long long verybig=12345678908642;
                                                              //����ȫ��ֻ�����������
    printf("un=%u and not %d.\n",un,un);                    //int�����ֵ С�� unsigned int�����ֵ�����Ե�uint��3000000000����ʾ��intʱ�����
    printf("end=%hd and not %d.\n",end,end);                /*int�����ֵ ���� short�����ֵ������û�����*/
    printf("big=%ld and not %hd.\n",big,big);               //short�����ֵ С�� long�����ֵ������long��65537����ʾ��shortʱ���
    printf("verybig=%lld and not %ld.\n",verybig,verybig);  //long�����ֵ Ч�� long long�����ֵ������long long��12345678908642����ʾ��longʱ�����

    return 0;
}
/*
����̨������ϣ�
long long-------64λ��
long -----------32λ��
int-------------32λ��
short-----------16λ��
*/
