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
	pstrvec.reset(new vector<string>(*item.pstrvec));//这是安全的？
	/*reset成员函数的实现其实是借由swap实现的：
	shared_ptr<vector<string>> pnew(new vector<string>(*item.pstrvec));
	ptemp=pnew;
	pnew=pstrvec;//pnew指向pstrvec原来所指向的动态内存
	pstrvec=ptemp;//pstrvec现在指向新产生的共享指针所指向的动态内存
	*/
	//当swap函数结束后，新产生的pnew和临时共享指针ptemp销毁，若pstrvec原引用计数为1，那么两者的销毁会导致原pstrvec所指向的动态对象也一起销毁
	//而pstrvec就会指向新的动态对象，所以使用reset完成StrBlob的自赋值是安全的。
	
	//当然也简单点也可以用p=q即共享指针的拷贝赋值运算符=完成
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