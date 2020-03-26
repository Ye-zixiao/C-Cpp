#ifndef _STRBLOB_H_

#include<string>
#include<memory>
#include<vector>
#include<initializer_list>
#include<stdexcept>

class StrBlob_ptr;
class cStrBlob_ptr;

class StrBlob {
	friend std::ostream& operator<<(std::ostream& os, const StrBlob& item);
	friend class cStrBlob_ptr;
	friend class StrBlob_ptr;
public:
	using size_type = std::vector<std::string>::size_type;
	using StrBlob_ptr = StrBlob_ptr;
	using cStrBlob_ptr = cStrBlob_ptr;

	StrBlob():
		pstrvec(std::make_shared<std::vector<std::string>>()){}
	StrBlob(std::initializer_list<std::string> il) :
		pstrvec(std::make_shared<std::vector<std::string>>(il)) {}//记得区分初始化列表和构造函数初始化（有些地方会在这多加个“器”字）列表的区别

	size_type size(void) const { return pstrvec->size(); }
	bool empty(void) const { return pstrvec->empty(); }
	void push_back(const std::string& str) { pstrvec->push_back(str); }
	void pop_back(void) { check(); pstrvec->pop_back(); }
	std::string& front(void) { check(); return pstrvec->front(); }
	const std::string& front(void) const { check(); return pstrvec->front(); }
	std::string& back(void) { check(); return pstrvec->back(); }
	const std::string& back(void) const { check(); return pstrvec->back(); }

	StrBlob& operator=(const StrBlob& item) {
		pstrvec = item.pstrvec;
		return *this;
	}

	StrBlob_ptr begin(void);
	StrBlob_ptr end(void);
	cStrBlob_ptr cbegin(void) const;
	cStrBlob_ptr cend(void) const;


	size_t use_count(void)const {
		return pstrvec.use_count();
	}

private:
	/*void check(size_type i, const string& msg) const;*/
	void check(void) const {
		if (pstrvec->empty())
			throw std::out_of_range("Container is empty!");
	}
	std::shared_ptr<std::vector<std::string>> pstrvec;
};

std::ostream& operator<<(std::ostream& os, const StrBlob& item)
{
	for (const auto& elem : *item.pstrvec)
		os << elem << ' ';
	return os;
}

class StrBlob_ptr {
public:
	StrBlob_ptr():
	    curr(0){}
	StrBlob_ptr(StrBlob&item,size_t c=0):
		wptr(item.pstrvec),curr(c){}

	StrBlob_ptr& operator=(const StrBlob_ptr& item) {
		wptr = item.wptr;
		curr = item.curr;
		return *this;
	}
	std::string& operator*() {
		check();
		return (*wptr.lock())[curr];
	}
	bool operator!=(const StrBlob_ptr& item) {
		return item.wptr.lock() != wptr.lock() || curr != item.curr;
	}
	StrBlob_ptr& operator++() {
		++curr;
		return *this;
	}
	StrBlob_ptr& operator--() {
		--curr;
		return *this;
	}

	bool expired(void) const{
		return wptr.expired();//用它来指明弱指针是否有没有绑定某个共享指针
	}

private:
	void check(void) {
		if (wptr.expired())
			throw std::runtime_error("StrBlob_ptr is nullptr");
		if (curr >= wptr.lock()->size())
			throw std::out_of_range("Out of range");
	}
	std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};

class cStrBlob_ptr {
public:
	cStrBlob_ptr():
	    curr(0){}
	cStrBlob_ptr(const StrBlob& item, size_t cu = 0):
		wptr(item.pstrvec),curr(cu){}

	cStrBlob_ptr& operator=(const cStrBlob_ptr& item) {
		this->curr = item.curr;
		this->wptr = item.wptr;
		return *this;
	}
	const std::string& operator*() const {
		check();
		return (*wptr.lock())[curr];
	}
	cStrBlob_ptr& operator--() {
		--curr;
		return *this;
	}
	cStrBlob_ptr& operator++() {
		++curr;
		return *this;
	}
	bool operator!=(const cStrBlob_ptr& item) const {
		return wptr.lock() != item.wptr.lock() || curr != item.curr;
	}


private:
	void check(void) const {
		if (wptr.expired())
			throw std::runtime_error("cStrBlob_ptr is nullptr");
		if (curr >= wptr.lock()->size())
			throw std::out_of_range("Out of range");
	}
	size_t curr;
	std::weak_ptr<std::vector<std::string>> wptr;
};

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

#endif // !_STRBLOB_H_
