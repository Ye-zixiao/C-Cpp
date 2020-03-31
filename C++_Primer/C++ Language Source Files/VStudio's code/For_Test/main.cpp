#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<unordered_map>
#include<set>
#include<fstream>
#include<sstream>
#include<initializer_list>
using namespace::std;

class StrBlob {
	
public:
	StrBlob():
		pstrvec(new vector<string>()){}
	StrBlob(initializer_list<string> sl) :
		pstrvec(new vector<string>{ sl }){}
	StrBlob(const StrBlob& item):
		pstrvec(new vector<string>(*item.pstrvec)){}
	StrBlob& operator=(const StrBlob& item);

	void push_back(const string& str) {
		pstrvec->push_back(str);
	}
	void pop_back(void) {
		pstrvec->pop_back();
	}

	ostream& print(ostream& os);

private:

	shared_ptr<vector<string>> pstrvec;
};

ostream& StrBlob::print(ostream& os)
{
	for (const auto& elem : *pstrvec)
		os << elem << ' ';
	return os;
}

StrBlob& StrBlob::operator=(const StrBlob& item)
{
	/*vector<string>* temp_pstrvec = new vector<string>(*item.pstrvec);
	pstrvec.reset(temp_pstrvec);*/
	pstrvec.reset(new vector<string>(*item.pstrvec));//���ǰ�ȫ�ģ�
	/*reset��Ա������ʵ����ʵ�ǽ���swapʵ�ֵģ�
	shared_ptr<vector<string>> pnew(new vector<string>(*item.pstrvec));
	ptemp=pnew;
	pnew=pstrvec;//pnewָ��pstrvecԭ����ָ��Ķ�̬�ڴ�
	pstrvec=ptemp;//pstrvec����ָ���²����Ĺ���ָ����ָ��Ķ�̬�ڴ�
	*/
	//��swap�����������²�����pnew����ʱ����ָ��ptemp���٣���pstrvecԭ���ü���Ϊ1����ô���ߵ����ٻᵼ��ԭpstrvec��ָ��Ķ�̬����Ҳһ������
	//��pstrvec�ͻ�ָ���µĶ�̬��������ʹ��reset���StrBlob���Ը�ֵ�ǰ�ȫ�ġ�
	
	//��ȻҲ�򵥵�Ҳ������p=q������ָ��Ŀ�����ֵ�����=���
	/*
	pstrvec=make_shared_ptr<vector<string>>(*item.pstrvec);
	*/
	
	return *this;
}

int main(void)
{
	StrBlob test{ "hello","world","china" };
	StrBlob test_cpy = test;
	test = test;

	test.print(cout) << endl;
	test_cpy.print(cout) << endl;

	return 0;
}