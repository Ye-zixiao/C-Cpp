/*-----����ֲ����������--------*/
#include<stdio.h>
#include<inttypes.h>
int main(void)
{
    int32_t me32;

    me32=45933945;
    printf("First ,assume int32_t is int: ");
    printf("me32=%d\n",me32);
    printf("Next, let's not make any assumptions.\n");
    printf("Instead,use a\"macro\"from inttypes.h: ");
    printf("me32=%"PRId32"\n",me32);                    /*��C99��C11��ʹ�á�PRId32����
                                                Ϊ����ȷ��int�����ڲ�ͬϵͳ���У���Ϊ���ȿ�����32λ��Ҳ������16λ��
                                                �������ӡ��ʱ������ʾ��Ϊ32λ����ֵ��
                                                �ȷ�˵��
                                                    ��intΪ32λ�Ļ����ϣ���ʾ���32λ��������Ҫ�õ�%d��
                                                    ������intΪ16λ�Ļ��������ǲ��ò�ȥʹ��%ldȥ��ӡ��
                                                Ϊ�˱��������鷳����ʹ��PRId32�����                       */

    return 0;
}
