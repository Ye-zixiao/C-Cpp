#include<iostream>
#include<cstdlib>
#include<new>
using namespace::std;

void operator delete(void* mem) noexcept {
	cout << "ordinary delete" << endl;
	free(mem);
}

void operator delete(void* mem,const nothrow_t& nt) noexcept {
	cout << "nothrow delete" << endl;
	free(mem);
}

//void operator delete(void* mem, void* second_ptr) noexcept {
//	cout << "placement delete" << endl;
//	free(mem);
//}

struct Test {
	Test() {
		throw 1;
	}
};

struct Raw {
	Raw() = default;
};

int main(void)
{
	//int* pvalue = new (nothrow) int(42);
	//delete pvalue;

	//try {
	//	//new (nothrow) Test();
	//	auto p = new (nothrow) Test();
	//}
	//catch (int& err) {
	//	cerr << err << endl;
	//}

	//int* pv = new int(5);
	//delete pv;

	try {
		auto p = new Raw();
		new (p) Test();//����ͼʹ�ö�λnew��ָ��ָ����ָ���λ���ϴ����µĶ��󣬵��������׳��˶��������ǵ��õ���ͨdelete������nothrow delete
						//��ô����Ӧ�û��ӡ��ص��������������������ڴ���ʧ�ܵ�����²�û�е����Զ����delete������˵�������õ��Ǳ�׼���ж����
						//��λoperator delete�������������λoperator delete�����ǲ��ܱ����صģ��Ͷ�λoperator new������ͬ�����ǲ������صģ�
	}
	catch (const int& err) {
		cerr << err << endl;
	}

	return 0;
}
