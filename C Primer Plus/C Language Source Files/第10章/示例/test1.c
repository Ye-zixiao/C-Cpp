#include<stdio.h>
int main(void)
{
	const int arr[3] = { 0 };
	int * parr = &arr;			//把const的数组数据的地址赋给了普通指针，这是会出错的，即使在这个编译器上通过了，但总有一天会出错的
	*parr = 2;

	printf("arr[0]=%d\n", arr[0]);

	return 0;
}
