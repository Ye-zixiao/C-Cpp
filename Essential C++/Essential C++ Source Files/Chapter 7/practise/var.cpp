/********************************

�ֿ��㷨��ԭʼ������Ӿ�����в�������ʹ�÷ֿ������н�ά���㣩��
ʹ����cache�е������ڱ��滻֮ǰ������޶ȵض��Ѿ�װ�����ݽ��з���

********************************/
#include<iostream>
using namespace std;
#define BLOCKSIZE 1

inline void do_block(int n,int si,int sj,int sk,int *arr1,int *arr2,int *arr3)//�����Ӿ���ĳ˷�
{
    for(int i=si;i<si+BLOCKSIZE;++i)
        for(int j=sj;j<sj+BLOCKSIZE;++j)
        {
            int cij=arr3[i+j*n];
            for(int k=sk;k<sk+BLOCKSIZE;++k)
                cij+=arr1[i+k*n]*arr2[k+j*n];
            arr3[i+j*n]=cij;
        }
}

void dgemm(int n,int *arr1,int *arr2,int *arr3)     //
{
    for(int sj=0;sj<n;sj+=BLOCKSIZE)
        for(int si=0;si<n;si+=BLOCKSIZE)
            for(int sk=0;sk<n;sk+=BLOCKSIZE)
                do_block(n,si,sj,sk,arr1,arr2,arr3);
}

void print(int* arr, int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cout << arr[i * n + j] << ' ';
			if (++count % n == 0)
				cout << endl;
		}
}

int main(void)
{
    int arr1[16] = {
		1,2,1,2,
		3,4,3,4,
		1,2,1,2,
		3,4,3,4,
	};
	int arr2[16] = {
		1,2,1,2,
		3,4,3,4,
		1,2,1,2,
		3,4,3,4,
	};
	int arr3[16] = {
		1,2,1,2,
		3,4,3,4,
		1,2,1,2,
		3,4,3,4,
	};

    dgemm(4,arr1,arr2,arr3);
    print(arr3,4);

    return 0;
}
