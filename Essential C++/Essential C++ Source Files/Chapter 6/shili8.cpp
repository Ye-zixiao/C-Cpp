#include<iostream>
#include<string>
using namespace std;

template<typename OutStream>
class PrintIt
{
public:
	PrintIt(OutStream& os)					//����ģ����Ҳ���Զ����Աģ�庯��
		:_os(os){}

	template<typename elemType>
	void print(const elemType &elem,char delimiter='\n')
	{
		_os << elem << delimiter;
	}

private:
	OutStream& _os;
};

int main(void)
{
	PrintIt<ostream> to_standard_out(cout);
	to_standard_out.print("hello");
	to_standard_out.print(1024);

	string my_string("i am a string");
	to_standard_out.print(my_string);

	return 0;
}
