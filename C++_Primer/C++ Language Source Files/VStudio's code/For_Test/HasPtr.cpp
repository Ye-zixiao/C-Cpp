#include"HasPtr.h"
//#define DEBUG

/*--------------------�������Ƴ�Ա----------------------*/

HasPtr::HasPtr(const HasPtr& item) :
	pstr(item.pstr),use(item.use) {
	if(pstr&&use)
		++* use;
}

HasPtr::HasPtr(HasPtr&& item)noexcept :
	pstr(std::move(item.pstr)), use(std::move(item.use)) {
#ifdef DEBUG
	std::cout << "HasPtr(HasPtr&&)" << std::endl;
#endif
	item.pstr = nullptr;
	item.use = nullptr;
}

//HasPtr&
//HasPtr::operator=(const HasPtr& rhs) {
//	if (this != &rhs) {
//		free();
//		pstr = rhs.pstr;
//		use = rhs.use;
//		++* use;
//	}
//	return *this;
//}

HasPtr&
HasPtr::operator=(HasPtr&& rhs)noexcept {
	if (this != &rhs) {
		free();
		pstr = std::move(rhs.pstr);
		use = std::move(rhs.use);
		rhs.pstr = nullptr;
		rhs.use = nullptr;
	}
	return *this;
}

//�����������汾�ĸ�ֵ�����
HasPtr& 
HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	return *this;
}

HasPtr::~HasPtr() {
	free();
}

std::string&
operator*(const HasPtr& item) {
	if (!item.pstr)
		throw std::runtime_error("Dereference failed!");
	return *item.pstr;
}

/*---------------����ǳ�Ա������˽�й��ߺ���----------------------*/

void
HasPtr::free(void) {
	if (pstr && -- * use == 0) {
		delete pstr;
		delete use;
		pstr = nullptr;
		use = nullptr;
	}
}

void swap(HasPtr& lhs, HasPtr& rhs) {
	using std::swap;
	swap(lhs.pstr, rhs.pstr);
	swap(lhs.use, rhs.use);
}