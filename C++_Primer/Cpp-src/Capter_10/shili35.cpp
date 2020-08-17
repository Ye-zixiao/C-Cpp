#include<vector>
#include<list>
#include<iostream>
#include<algorithm>
#include<iterator>
using namespace::std;

int * endp(int* parr, size_t sz)
{
	return parr + sz - 1;
}

int* beginp(int* parr)
{
	return parr;
}

void swap(int* pvalue1, int* pvalue2)
{
	int temp = *pvalue1;
	*pvalue1 = *pvalue2;
	*pvalue2 = temp;
}

void reverse_arr(int* beg, int* end)
{
	for (; beg < end; ++beg, --end)
		swap(beg, end);
}

int main(void)
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	reverse_arr(beginp(arr), endp(arr, sizeof(arr) / sizeof(int)));
	for (const auto& i : arr)cout << i << ' '; cout << endl;

	return 0;
}
