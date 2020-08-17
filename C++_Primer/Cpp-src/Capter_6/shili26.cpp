#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
//#define NDEBUG
using namespace::std;

int add(int lvalue, int rvalue)
{
#ifndef NDEBUG
	cout << __func__ << ":";
#endif
	return lvalue + rvalue;
}

int sub(int lvalue, int rvalue)
{
#ifndef NDEBUG
	cout << __func__ << ":";
#endif
	return lvalue - rvalue;
}

int multi(int lvalue, int rvalue)
{
#ifndef NDEBUG
	cout << __func__ << ":";
#endif
	return lvalue * rvalue;
}

/*
int divi(int lvalue, int rvalue)
{
#ifndef NDEBUG
	cout << __func__ << ":";
#endif
	try {
		if (rvalue == 0)
			throw runtime_error("Second number can't be 0");
		return lvalue / rvalue;
	}
	catch (runtime_error err){
		cout << err.what() << "\n\treturn:";
		return 0;
	}
}
*/

//��Ȼ�����������Ҳ����ʹ��������������
int divi(int lvalue,int rvalue)
{
#ifndef NDEBUG
    cout<<__func__<<":";
#endif // NDEBUG
    return rvalue!=0?lvalue/rvalue:0;
}

int main(void)
{
	//vector<int (*)(int, int)> pf_vec;	//1��ʹ��ֱ�ӷ����壺����һ��vector����Ԫ������Ϊ����ָ�롢
	//vector<decltype(add)*> pf_vec;	//2��ʹ��decltype�ñ������Զ�ȥ�б�
	using PF = int (*)(int, int);		//3��ʹ�����ͱ�������
	vector<PF> pfvec{ add,sub,multi,divi };

	for (auto& pf : pfvec)
		cout << pf(10, 0) << endl;

	return 0;
}
