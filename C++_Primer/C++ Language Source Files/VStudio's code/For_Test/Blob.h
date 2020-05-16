#ifndef _BLOB_H_
#define _BLOB_H_

#include<memory>
#include"Memory.h"
#include<vector>
#include<utility>
#include<initializer_list>
#include<stdexcept>

template<typename>
class Blob;
template<typename>
class Blob_ptr;
template<typename>
class Blob_cptr;
template<typename T>
bool operator==(const Blob<T>&, const Blob<T>&);
template<typename T>
bool operator!=(const Blob<T>&, const Blob<T>&);

template<typename T>
class Blob {//自定义容器，嵌套了一个vector
	friend class Blob_ptr<T>;
	friend class Blob_cptr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
	friend bool operator!=<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	Blob() :pdata(new std::vector<T>()) {}
	template<typename Iter> Blob(Iter b, Iter e):
		pdata(new std::vector<T>(b,e)){}
	Blob(std::initializer_list<T> il) :
		pdata(new std::vector<T>(il)) {}

	T& operator[](size_type n);
	const T& operator[](size_type n)const;
	size_type size(void)const { return pdata->size(); }
	bool empty(void) const { return pdata->empty(); }
	void push_back(T&& value) { pdata->push_back(std::move(value)); }
	void pop_back(void);
	T& front(void);
	T& back(void);
	Blob_ptr<T> begin(void);
	Blob_cptr<T> cbegin(void);
	Blob_ptr<T> end(void);
	Blob_cptr<T> cend(void);

private:
	//Shared_ptr<std::vector<T>> pdata;//使用自定义的Shared_ptr替换STL的shared_ptr
	std::shared_ptr<std::vector<T>> pdata;
};

template<typename T>
bool operator==(const Blob_ptr<T>&, const Blob_ptr<T>&);
template<typename T>
bool operator!=(const Blob_ptr<T>&, const Blob_ptr<T>&);

template<typename T>
class Blob_ptr {//Blob的普通迭代器
	friend bool operator==<T>(const Blob_ptr<T>&, const Blob_ptr<T>&);
	friend bool operator!=<T>(const Blob_ptr<T>&, const Blob_ptr<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	Blob_ptr() = default;
	Blob_ptr(Blob<T>&item,size_type n=0):
		wptr(item.pdata),curr(n){}

	T& operator*()const;
	T* operator->()const;
	Blob_ptr& operator++();
	Blob_ptr& operator--();
	Blob_ptr operator++(int);
	Blob_ptr operator--(int);

private:
	size_type curr = 0;
	std::weak_ptr<std::vector<T>> wptr;
};


template<typename T>
bool operator==(const Blob_cptr<T>&, const Blob_cptr<T>&);
template<typename T>
bool operator!=(const Blob_cptr<T>&, const Blob_cptr<T>&);

template<typename T>
class Blob_cptr {//Blob的常量迭代器
	friend bool operator==<T>(const Blob_cptr<T>&, const Blob_cptr<T>&);
	friend bool operator!=<T>(const Blob_cptr<T>&, const Blob_cptr<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	Blob_cptr() = default;
	Blob_cptr(const Blob<T>& item, size_type n=0):
		cwptr(item.pdata),curr(n){}

	const T& operator*() const;
	Blob_cptr<T>& operator++();

private:
	size_type curr = 0;
	std::weak_ptr<std::vector<T>> cwptr;
};

/*-----------------函数定义-------------------------*/
template<typename T>
inline bool operator==(const Blob<T>& lhs, const Blob<T>& rhs) {
	return *lhs.pdata == *rhs.pdata;
}

template<typename T>
inline bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
T& Blob<T>::operator[](size_type n){
	if (n >= size())
		throw std::out_of_range("Out of range");
	return (*pdata)[n];
}

template<typename T>
const T& Blob<T>::operator[](size_type n)const {
	if (n >= size())
		throw std::out_of_range("Out of range");
	return (*pdata)[n];
}

template<typename T>
inline void Blob<T>::pop_back(void) {
	if (empty())
		throw std::out_of_range("Blob is empty1");
	pdata->pop_back();
}

template<typename T>
inline T& Blob<T>::front(void) {
	if (empty())
		throw std::out_of_range("Blob is empty!");
	return (*pdata)[0];
}

template<typename T>
inline T& Blob<T>::back(void) {
	if (empty())
		throw std::out_of_range("Blob is empty!");
	return pdata->back();
}

template<typename T>
inline Blob_ptr<T> Blob<T>::begin(void) {
	return Blob_ptr<T>(*this);
}

template<typename T>
inline Blob_cptr<T> Blob<T>::cbegin(void) {
	return Blob_cptr<T>(*this);
}

template<typename T>
inline Blob_cptr<T> Blob<T>::cend(void) {
	return Blob_cptr<T>(*this, size());
}

template<typename T>
inline Blob_ptr<T> Blob<T>::end(void) {
	return Blob_ptr<T>(*this, size());
}

//

template<typename T>
bool operator==(const Blob_ptr<T>& lhs, const Blob_ptr<T>& rhs) {
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

template<typename T>
bool operator!=(const Blob_ptr<T>& lhs, const Blob_ptr<T>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
T& Blob_ptr<T>::operator*()const {
	if (wptr.expired() || curr >= wptr.lock()->size()||curr<0)
		throw std::out_of_range("Out of range");
	return (*wptr.lock())[curr];
}

template<typename T>
T* Blob_ptr<T>::operator->() const{
	return &(this->operator*());
}

template<typename T>
Blob_ptr<T>& Blob_ptr<T>::operator++() {
	++curr;
	return *this;
}

template<typename T>
Blob_ptr<T> Blob_ptr<T>::operator++(int) {
	Blob_ptr ret(*this);
	++curr;
	return ret;
}

template<typename T>
Blob_ptr<T>& Blob_ptr<T>::operator--() {
	--curr;
	return *this;
}

template<typename T>
Blob_ptr<T> Blob_ptr<T>::operator--(int) {
	Blob_ptr ret(*this);
	--curr;
	return ret;
}

//

template<typename T>
bool operator==(const Blob_cptr<T>& lhs, const Blob_cptr<T>& rhs) {
	return lhs.cwptr.lock() == rhs.cwptr.lock() && lhs.curr == rhs.curr;
}

template<typename T>
bool operator!=(const Blob_cptr<T>& lhs, const Blob_cptr<T>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
inline const T& Blob_cptr<T>::operator*() const{
	if (cwptr.expired() || curr >= cwptr.lock()->size() || curr < 0)
		throw std::out_of_range("Empty or Out of range");
	return (*cwptr.lock())[curr];
}

template<typename T>
inline Blob_cptr<T>& Blob_cptr<T>::operator++() {
	++curr;
	return *this;
}

#endif
