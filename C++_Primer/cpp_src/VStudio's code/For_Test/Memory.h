#ifndef _MEMORY_H_
#define _MEMORY_H_
//#define DEBUG
#include<iostream>
#include<functional>


template<typename T>
struct Deleter {
	void operator()(T* p) {
#ifdef DEBUG
		std::cout << "deleting obj..." << std::endl;
#endif
		delete p;
	}
};


template<typename T,typename D=Deleter<T>>
class Unique_ptr {
public:
	Unique_ptr():deleter(D()){}
	Unique_ptr(T* p,D d=D()):
		ptr(p),deleter(d){}
	Unique_ptr(const Unique_ptr&) = delete;
	~Unique_ptr() {
		deleter(ptr);
	}

	T& operator=(const T&) = delete;
	T& operator*();
	const T& operator*() const;
	T* operator->();
	const T* operator->() const;

private:
	T* ptr = nullptr;
	D deleter;
	//Unique_ptr��ͨ��ֱ�������б���ɾ��������ķ�ʽ��ʵ�ּ��ٵ���ɾ���������Ŀ���
};


/*---------------------------------Unique_ptr��Ա��������-----------------------------*/
template<typename T,typename D>
inline T& Unique_ptr<T,D>::operator*() {
	if (!ptr)throw std::runtime_error("Nothing to point");
	return *ptr;
}

template<typename T,typename D>
const T& Unique_ptr<T,D>::operator*() const {
	if (!ptr)throw std::runtime_error("Nothing to point");
	return *ptr;
}

template<typename T,typename D>
T* Unique_ptr<T,D>::operator->() {
	return &this->operator*();
}

template<typename T,typename D>
const T* Unique_ptr<T,D>::operator->() const {
	return &this->operator();
}



template<typename T>
class Shared_ptr {
public:
	Shared_ptr() = default;
	Shared_ptr(T* p):
		pcount(new unsigned(1)),ptr(p){}
	Shared_ptr(T* p,std::function<void (T*)> f):
		pcount(new unsigned(1)),ptr(p),del(new std::function<void (T*)>(f)){}
	Shared_ptr(const Shared_ptr&);
	~Shared_ptr();

	Shared_ptr<T>& operator=(const Shared_ptr&);
	T& operator*();
	const T& operator*()const;
	T* operator->();
	const T* operator->() const;
	unsigned use_count(void)const;
	void release(void);

private:
	void free(void);
	unsigned* pcount = nullptr;
	T* ptr = nullptr;
	std::function<void(T*)>* del = nullptr;
	//Shared_ptr��ɾ����ʵ������ͨ�������б����ָ��function���Ͷ����ָ��Ľ����õ�����ʵ��
};


/*--------------------------Shared_ptr��Ա��������----------------------------*/
template<typename T>
inline T& Shared_ptr<T>::operator*() {
	if (!ptr)throw std::runtime_error("Nothing to point");
	return *ptr;
}

template<typename T>
inline T* Shared_ptr<T>::operator->(){
	return &this->operator*();
}

template<typename T>
inline const T* Shared_ptr<T>::operator->() const{
	return &this->operator*();
}

template<typename T>
void Shared_ptr<T>::free(void) {
	if (ptr && --*pcount == 0) {
#ifdef DEBUG
		std::cout << "free()" << std::endl;
#endif
		del ? (*del)(ptr) : delete ptr;
		delete pcount;
		delete del;
	}
	pcount = nullptr;
	del = nullptr;
	ptr = nullptr;
}

template<typename T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr& sp) :
	pcount(sp.pcount), ptr(sp.ptr), del(sp.del) {
	++* pcount;
}

template<typename T>
Shared_ptr<T>::~Shared_ptr() {
	free();
}

template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(const Shared_ptr& sp) {
	if (this != &sp) {
		free();
		ptr = sp.ptr;
		del = sp.del;
		pcount = sp.pcount;
		++*pcount;
	}
	return *this;
}

template<typename T>
inline void Shared_ptr<T>::release(void) {
	free();
}

template<typename T>
unsigned Shared_ptr<T>::use_count(void)const {
	return pcount ? *pcount : 0;
}

template<typename T>
const T& Shared_ptr<T>::operator*() const {
	if (!ptr)throw std::runtime_error("Nothing to point");
	return *ptr;
}


/*----------------------------���������ߺ���---------------------*/

template<typename T,typename... Args>
Shared_ptr<T> make_Shared(Args&&... args) {
	auto p = new T(std::forward<Args>(args)...);
	return Shared_ptr<T>(p);
}


#endif