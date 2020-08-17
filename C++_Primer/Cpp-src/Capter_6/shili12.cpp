#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<initializer_list>
using namespace::std;

/*方法1：使用<传统的维度在参数列表后>的方法来返回指向数组的指针或者指向数组的引用*/
const string(&function(const string(&ref_str_arr)[3]))[3]
{
	return ref_str_arr;
}

const string(*function(const string(*pstr_2d)[3]))[3]//传统的较为复杂的返回指向数组的指针的函数写法，
//且要求一定写明指针指向的数组的维度，同理对于函数的形参也是这么要求的
{
	return pstr_2d;
}

/*方法2：使用尾置返回类型法来比较简单的表明返回指针类型*/
//auto function(const string(*pstr_2d)[3])->const string(*)[3]
//{
//	return pstr_2d;
//}

/*方法3：使用using或者typedef简化数组的类型写法*/
//using strarr = const string[3];
//
//strarr* function(const string(*pstr_2d)[3])
//{
//	return pstr_2d;
//}

//不建议使用decltype关键字来指定数组类型，因为decltype使用的前提是数组必须定义在decltype的前面，
//decltype才能判断数组的类型，在很多情况下反而有点鸡肋

int main(void)
{
	string strarr[3] = { "hello","world","china" };
	for (unsigned i = 0; i != 3; ++i)
		cout << function(strarr)[i] << ' ';
	cout << endl;

	cout << "===============================" << endl;
	string strarr_2d[3][3]{ "hello","world","china","america",
		"japan","korean","nipen","show","code" };
	for (unsigned i = 0; i != 3; ++i)
	{
		for (unsigned j = 0; j != 3; ++j)
			cout << *(*(function(strarr_2d) + i) + j) << ' ';
		cout << endl;
	}

	return 0;
}
