#include"StrBlob.h"

/*
*StrBlob�ࣺ����һ��������ɶ�̬�ڴ�������vector<string>
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

/*
std::ostream& operator<<(std::ostream& os, const StrBlob& item)
{
	for (const auto& elem : *item.pstrvec)
		os << elem << ' ';
	return os;
}*/