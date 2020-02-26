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

//上下两者就发生重载冲突，说明上下等价，所以上面的声明方式是对的
//pfuc function(pfuc pf)
//{
//	return pf;
//}

int main(void)
{
	return 0;
}