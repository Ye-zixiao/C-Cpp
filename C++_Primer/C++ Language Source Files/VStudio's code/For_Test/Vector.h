#ifndef _VECTOR_H_
#define _VECTOR_H_

/*
@author name: Ye-zixiao
@container/class'name: Vector
@usage: To imitate STL container <vector>'s normal usage,but can't use algorithm on it
@write date/location: 2020-05-08 at home
*/

#include<memory>
#include<utility>
#include<algorithm>
#include<initializer_list>
#include<stdexcept>
#include<iterator>

template<typename>
class Vector;
template<typename>
class Iterator;
template<typename T>
bool operator==(const Vector<T>&, const Vector<T>&);
template<typename T>
bool operator!=(const Vector<T>&, const Vector<T>&);

template<typename T>
class Vector {	
	friend bool operator==<T>(const Vector<T>&, const Vector<T>&);
	friend bool operator!=<T>(const Vector<T>&, const Vector<T>&);
	friend class Iterator<T>;
public:
	typedef T value_type;
	typedef std::size_t size_type;

	Vector() = default;
	Vector(std::initializer_list<T> il);
	Vector(size_type n, value_type value = T());
	Vector(const T* b, const T* e);
	Vector(const Vector<T>&);
	Vector(Vector&& item)noexcept;
	~Vector() { free(); }
	Vector& operator=(const Vector& item);
	Vector& operator=(Vector&& item)noexcept;
	T& operator[](size_type n);
	const T& operator[](size_type n)const;

	bool empty(void) const { return pbegin ? plast == pbegin : true; }
	size_type size(void) const { return pbegin ? plast - pbegin : 0; }
	size_type capacity(void) const { return pbegin ? pend - pbegin : 0; }
	void push_back(const T&value) { chk_n_alloc(); alloc.construct(plast++, value); }
	void push_back(T&& value) { chk_n_alloc(); alloc.construct(plast++, std::move(value)); }
	Iterator<T> insert(Iterator<T> iter, const T&);
	Iterator<T> insert(Iterator<T> iter, T&&);	
	/*insert成员函数的主要难点在于当我们给定一个迭代器后，若容器中的空间不足就会重新分配内容空间，原来指向它的指针就会不在有效。
		所以我们在策略是是先检验给定的迭代器确实是指向该容器的，然后扩容容器大小移动原来的元素，最后插入到指定的位置上（此时用迭
		代器中的curr游标指定）*/
	void pop_back(void) { if (!empty())alloc.destroy(--plast); }
	void clear(void);
	void resize(size_type n);
	void reserve(size_type n);
	void shrink_to_fit(void);
	T& back(void) { if (empty())throw std::out_of_range("empty!"); return *(plast - 1); }
	T& front(void) { if (empty())throw std::out_of_range("empty!"); return *pbegin; }
	Iterator<T> begin(void);
	Iterator<T> end(void);

private:
	void free(void);
	void move_mem(size_type n);	//将当前容器中的元素移动到新的大内存中
	void chk_n_alloc(void);
	std::pair<T*, T*> alloc_n_cpy(const T* b, const T* e);
	void reallocate(void);
	static std::allocator<T> alloc;
	T* pbegin = nullptr;
	T* plast = nullptr;
	T* pend = nullptr;
};


template<typename T>
bool operator==(const Iterator<T>&, const Iterator<T>&);
template<typename T>
bool operator!=(const Iterator<T>&, const Iterator<T>&);


template<typename T>
class Iterator {
	friend bool operator==<T>(const Iterator<T>&, const Iterator<T>&);
	friend bool operator!=<T>(const Iterator<T>&, const Iterator<T>&);
	friend class Vector<T>;
public:
	typedef T value_type;
	typedef typename Vector<T>::size_type size_type;

	Iterator() = default;
	Iterator(Vector<T>& item, size_type n = 0);

	T* operator->();
	T& operator*();
	Iterator& operator++();
	Iterator operator++(int);
	Iterator& operator--();
	Iterator operator--(int);

private:
	T* pbegin = nullptr;//用于比对它是否是指向哪个容器的迭代器
	size_type curr = 0;
};


/*----------------------------------函数定义-------------------------------------*/
template<typename T>
std::allocator<T> Vector<T>::alloc;

template<typename T>
bool operator==(const Vector<T>& lhs, const Vector<T>& rhs) {
	if (lhs.size() == rhs.size()) {
		for (std::size_t i = 0; i < lhs.size(); ++i)
			if (lhs[i] != rhs[i])
				return false;
		return true;
	}
	return false;
}

template<typename T>
void Vector<T>::free(void) {
	if (pbegin) {
		std::for_each(pbegin, plast, [](T& value) {alloc.destroy(&value); });
		alloc.deallocate(pbegin, capacity());
		pbegin = plast = pend = nullptr;
	}
}

template<typename T>
inline bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
std::pair<T*, T*> Vector<T>::alloc_n_cpy(const T* b, const T* e) {
	const auto ret = alloc.allocate(e - b);
	return { ret,std::uninitialized_copy(b,e,ret) };
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> il) {
	auto ret = alloc_n_cpy(il.begin(), il.end());
	pbegin = ret.first;
	plast = pend = ret.second;
}

template<typename T>
Vector<T>::Vector(const Vector& item) {
	auto ret = alloc_n_cpy(item.cbegin(), item.cend());
	pbegin = ret.first;
	plast = pend = ret.second;
}

template<typename T>
Vector<T>::Vector(size_type n, value_type value) {
	pbegin = alloc.allocate(n);
	std::uninitialized_fill(pbegin, pbegin + n, value);
	plast = pend = pbegin + n;
}


template<typename T>
Vector<T>::Vector(const T*b,const T*e):
	pbegin(alloc.allocate(e-b)),plast(std::uninitialized_copy(b,e,pbegin)),pend(plast){}

template<typename T>
T& Vector<T>::operator[](size_type n) {
	return pbegin[n];
}

template<typename T>
const T& Vector<T>::operator[](size_type n) const {
	return pbegin[n];
}

template<typename T>
void Vector<T>::chk_n_alloc(void) {
	if (plast == pend)reallocate();
}

template<typename T>
void Vector<T>::move_mem(size_type n) {
	auto ret = alloc.allocate(n);
	auto pdest = ret;
	std::for_each(pbegin, plast, [&](T& value) {alloc.construct(pdest++, std::move(value)); });
	free();
	pbegin = ret;
	plast = pdest;
	pend = ret + n;
}

template<typename T>
void Vector<T>::reallocate(void) {
	auto new_capacity = capacity() ? capacity() * 2 : 1;
	move_mem(new_capacity);
}


template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& item) {
	if (this != &item) {
		auto ret = alloc_n_cpy(item.cbegin(), item.cend());
		free();
		pbegin = ret.first;
		plast = pend = ret.second;
	}
	return *this;
}

template<typename T>
void Vector<T>::clear(void) {
	if (!empty()) {
		std::for_each(pbegin, plast, [](T& value) {alloc.destroy(&value); });
		plast = pbegin;
	}
}

template<typename T>
Vector<T>::Vector(Vector&& item) noexcept{
	auto ret = alloc.allocate(item.size());
	pbegin = ret;
	plast = pend = std::uninitialized_copy(std::make_move_iterator(item.begin()), std::make_move_iterator(item.end()), ret);
	item.free();
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& item)noexcept {
	if (this != &item) {
		free();
		auto ret = alloc.allocate(item.size());
		pbegin = ret;
		plast = pend = std::uninitialized_copy(std::make_move_iterator(item.begin()), std::make_move_iterator(item.end()), ret);
		item.free();
	}
	return *this;
}

template<typename T>
inline void Vector<T>::shrink_to_fit(void) {
	if (!empty())move_mem(size());
}

template<typename T>
inline void Vector<T>::reserve(size_type n) {
	if (n > capacity()) move_mem(n);
}

template<typename T>
void Vector<T>::resize(size_type n) {
	if (n >= capacity()) {
		move_mem(n);
		std::uninitialized_fill(plast, pend, T());
		plast = pend = pbegin + n;
	}
	else if (n > size()) {
		std::uninitialized_fill_n(plast, n - size(), T());
		plast = pbegin + n;
	}
	else {
		std::destroy(pbegin + n, plast);
		plast = pbegin + n;

	}
}

template<typename T>
Iterator<T> Vector<T>::begin(void) {
	return Iterator(*this);
}

template<typename T>
Iterator<T> Vector<T>::end(void) {
	return Iterator(*this, size());
}

template<typename T>
Iterator<T> Vector<T>::insert(Iterator<T> iter, const T& value) {
	if (iter.pbegin != pbegin)throw std::runtime_error("This Iterator is not point at this object");
	chk_n_alloc();
	auto pos = iter.curr;
	if (pos == size())
		alloc.construct(plast++, value);
	else {
		auto this_curr = size();
		auto p = plast;
		alloc.construct(plast++, std::move(*(--p))); --this_curr;
		while (pos != this_curr) {
			*p = std::move(*(p - 1));
			--p;
			--this_curr;
		}
		pbegin[pos] = value;
	}
	return Iterator(*this, pos);
}

template<typename T>
Iterator<T> Vector<T>::insert(Iterator<T> iter, T&& value) {
	if (iter.pbegin != pbegin)throw std::runtime_error("This Iterator is not point at this object");
	chk_n_alloc();
	auto pos = iter.curr;
	if (pos == size())
		alloc.construct(plast++, std::move(value));
	else {
		auto this_curr = size();
		auto p = plast;
		alloc.construct(plast++, std::move(*(--p))); --this_curr;
		while (pos != this_curr) {
			*p = std::move(*(p - 1));
			--p;
			--this_curr;
		}
		pbegin[pos] = std::move(value);
	}
	return Iterator(*this, pos);
}

/*-----------------------------Iterator的函数定义---------------------------*/
template<typename T>
bool operator==(const Iterator<T>& lhs, const Iterator<T>& rhs) {
	return lhs.pbegin == rhs.pbegin && lhs.curr == rhs.curr;
}

template<typename T>
bool operator!=(const Iterator<T>& lhs, const Iterator<T>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
Iterator<T>::Iterator(Vector<T>&item,size_type n):
	pbegin(item.pbegin),curr(n){}

template<typename T>
T& Iterator<T>::operator*() {
	if (!pbegin)
		throw std::runtime_error("No Vector to point");
	return pbegin[curr];
}

template<typename T>
T* Iterator<T>::operator->() {
	if (!pbegin)
		throw std::runtime_error("No Vector to point");
	return &this->operator*();
}

template<typename T>
Iterator<T>& Iterator<T>::operator++() {
	++curr;
	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int) {
	Iterator ret(*this);
	++curr;
	return ret;
}

template<typename T>
Iterator<T>& Iterator<T>::operator--() {
	--curr;
	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator--(int) {
	Iterator ret(*this);
	--curr;
	return ret;
}

#endif

/*这是用原始指针实现的insert的不良示范*/
//template<typename T>
//T* Vector<T>::insert(T* iter, const T& value) {
//	chk_n_alloc();
//	if (plast == iter)
//		alloc.construct(plast++, value);
//	else {
//		auto p = plast;
//		alloc.construct(plast++, std::move(*(--p)));
//		while (p != iter) {
//			*p = std::move(*(p - 1));
//			--p;
//		}
//		*p = value;
//	}
//	return iter;
//}
//
//template<typename T>
//T* Vector<T>::insert(T* iter, T&& value) {
//	chk_n_alloc();
////移动后begin这个位置改变了,STL中的insert之所以能用是因为它们使用的iterator记录了索引而不是某个元素的地址
//	if (plast == iter)
//		alloc.construct(plast++, std::move(value));
//	else {
//		auto p = plast;
//		alloc.construct(plast++, std::move(*(--p)));
//		while (p != iter) {
//			std::cout << *iter << std::endl;
//			std::cout << *(p-1) << "->" << *p << std::endl;
//			*p = std::move(*(p - 1));
//			--p;
//		}
//		*p = std::move(value);
//	}
//	return iter;
//}