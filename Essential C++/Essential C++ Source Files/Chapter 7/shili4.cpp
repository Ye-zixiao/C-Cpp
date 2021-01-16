#include<iostream>
#include<string>
#include<sstream>
#include<exception>
using namespace std;

class test :public exception
{
public:
	test(int index,int max)
		:_index(index),_max(max)
	{}

	int index(void) const { return _index; }
	int max(void) const { return _max; }

	virtual const char* what(void) const;//���������vs���������е�

private:
	int _index;
	int _max;
};

const char* test::
what(void) const
{
	ostringstream ex_msg;
	static string msg;

	ex_msg << "Internal error:current index "
		<< _index << " exceeds maximum bound: "
		<< _max;
	msg = ex_msg.str();

	return msg.c_str();
}

int main(void)
{

	try
	{
		if (30 > 20)
			throw test(30, 20);			//�׳���׼�쳣�����������
	}
	catch (const exception & ex)
	{
		cerr << ex.what() << endl;
	}

	return 0;
}
