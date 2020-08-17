#ifndef _VECTOR_H_
#define _VECTOR_H_

#include<memory>
#include<utility>
#include<algorithm>
#include<initializer_list>
#include<stdexcept>

template<typename>
class Vector;
template<typename T>
bool operator==(const Vector<T>&, const Vector<T>&);
template<typename T>
bool operator!=(const Vector<T>&, const Vector<T>&);

template<typename T>
class Vector {
	friend bool operator==<T>(const Vector<T>&, const Vector<T>&);
	friend bool operator!=<T>(const Vector<T>&, const Vector<T>&);
public:
	typedef T value_type;
	typedef std::size_t size_type;

	Vector() = default;
	Vector(std::initializer_list<T> il);
	Vector(value_type value, size_type n);
	Vector(const T* b, const T* e);
	Vector(const Vector& item);
	Vector(Vector&& item)noexcept;
	~Vector() { free(); }
	Vector& operator=(const Vector& item);
	Vector& operator=(Vector&& item)noexcept;
	T& operator[](size_type n);
	const T& operator[](size_type n)const;

	bool empty(void) const;
	size_type size(void) const{return pbegin?plast-pbegin:0;}
	size_type capacity(void) const{return pbegin?pend-pbegin:0;}
	void push_back(const T&);
	void push_back(T&&);
	T* insert(T* iter, const T&);
	T* insert(T* iter, T&&);
	void pop_back(void);
	void clear(void);
	void resize(size_type n);
	void reserve(size_type n);
	void shrink_to_fit(void);
	T* begin(void);
	const T* cbegin(void) const;
	T* end(void);
	const T* cend(void) const;

private:
	void free(void);
	void move_mem(size_type n);
	void chk_n_alloc(void);
	std::pair<T*, T*> alloc_n_cpy(const T* b, const T* e);
	void reallocate(void);
	static std::allocator<T> alloc;
	T* pbegin = nullptr;
	T* plast = nullptr;
	T* pend = nullptr;
};


/*-----------------------º¯Êý¶¨Òå----------------------*/
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
Vector<T>::Vector(value_type value, size_type n) :
	pbegin(alloc.allocate(n)),plast(std::uninitialized_fill(pbegin,pbegin+n,value)),pend(plast){}


template<typename T>
Vector<T>::Vector(const T*b,const T*e):
	pbegin(alloc.allocate(e-b)),plast(std::uninitialized_copy(b,e,pbegin)),pend(plast){}


#endif
