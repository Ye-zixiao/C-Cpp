#include<iostream>
#include<string>
#include<vector>
using namespace::std;

using parr_2d = const int(*)[4];
using pfuc = parr_2d(*)(parr_2d);
const int(*(*function(const int(*(*pf)(const int(*)[4]))[4]))(const int(*)[4]))[4]
{
	return pf;
}

//�������߾ͷ������س�ͻ��˵�����µȼۣ����������������ʽ�ǶԵ�
//pfuc function(pfuc pf)
//{
//	return pf;
//}

int main(void)
{
	return 0;
}