#include"StrBlob.h"

/*
*StrBlob类：保存一个共享的由动态内存分配出的vector<string>
*/

StrBlob::StrBlob_ptr StrBlob::begin(void)
{
	return StrBlob_ptr(*this);
}

StrBlob::StrBlob_ptr StrBlob::end(void)
{
	return StrBlob_ptr(*this, pstrvec->size());
}

StrBlob::cStrBlob_ptr StrBlob::cbegin(void) const
{
	return cStrBlob_ptr(*this);
}

StrBlob::cStrBlob_ptr StrBlob::cend(void) const
{
	return cStrBlob_ptr(*this, pstrvec->size());
}

bool operator==(const StrBlob& lhs, const StrBlob& rhs) {
	return *lhs.pstrvec == *rhs.pstrvec;
}

bool operator!=(const StrBlob&lhs,const StrBlob&rhs){
	return !(*lhs.pstrvec == *rhs.pstrvec);
}

bool operator==(const StrBlob_ptr& lhs, const StrBlob_ptr& rhs) {
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlob_ptr& lhs, const StrBlob_ptr& rhs) {
	return !(lhs == rhs);
}

StrBlob_ptr operator+(const StrBlob_ptr& lhs, size_t n) {
	StrBlob_ptr temp(lhs);
	temp += n;
	return temp;
}

StrBlob_ptr operator-(const StrBlob_ptr& lhs, size_t n) {
	StrBlob_ptr temp(lhs);
	temp -= n;
	return temp;
}

cStrBlob_ptr operator+(const cStrBlob_ptr& lhs, size_t n) {
	cStrBlob_ptr temp(lhs);
	temp += n;
	return temp;
}
/*
std::ostream& operator<<(std::ostream& os, const StrBlob& item)
{
	for (const auto& elem : *item.pstrvec)
		os << elem << ' ';
	return os;
}*/