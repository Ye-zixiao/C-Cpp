#ifndef _BLOB_H_
#define _BLOB_H_

#include<iostream>
#include<memory>
#include<vector>
#include<initializer_list>

template<typename> class BlobPtr;
template<typename> class Blob;
template<typename T>
bool operator==(const Blob<T>&, const Blob<T>&);
template<typename T>
bool operator!=(const Blob<T>&, const Blob<T>&);


template<typename T>
class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
	friend bool operator!=<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	Blob():data(new std::vector<T>()){}
	Blob(std::initializer_list<T> il):data(new std::vector<T>(il)){}

	T& operator[](size_type n) {
		return (*data)[n];
	}
	size_type size(void) const { return data->size(); }
	bool empty(void) const { return data->empty(); }
	void push_back(T&& value) { data->push_back(std::move(value)); }
	void pop_back(void) { data->pop_back(); }
	BlobPtr<T> begin(void);
	BlobPtr<T> end(void);
	T& front(void) { return data->front(); }
	T& back(void) { return data->back(); }


private:
	std::shared_ptr<std::vector<T>> data;

};

template<typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T>
bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);

template<typename T>
class BlobPtr {
	friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	BlobPtr():curr(0){}
	BlobPtr(Blob<T>&item,size_type n = 0):
		wptr(item.data),curr(n){}

	T& operator*()const {
		auto ret = wptr.lock();
		return (*ret)[curr];
	}
	T* operator->()const {
		return &this->operator*();
	}
	BlobPtr& operator++() {
		++curr;
		return *this;
	}
	BlobPtr operator++(int) {
		BlobPtr ret(*this);
		++curr;
		return ret;
	}
	BlobPtr& operator--() {
		--curr;
		return *this;
	}
	BlobPtr operator--(int) {
		BlobPtr ret(*this);
		--curr;
		return ret;
	}

private:
	std::weak_ptr<std::vector<T>> wptr;
	size_type curr;
};


/*-------------------------------成员函数定义部分--------------------------------*/

template<typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs) {
	return *lhs.data == *rhs.data;
}

template<typename T>
bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	//return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
	return lhs.curr==rhs.curr;
}

template<typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	return !(lhs == rhs);
}


template<typename T>
BlobPtr<T> Blob<T>::begin(void) {
	return BlobPtr<T>(*this);
}

template<typename T>
BlobPtr<T> Blob<T>::end(void) {
	return BlobPtr<T>(*this, size());
}

#endif
