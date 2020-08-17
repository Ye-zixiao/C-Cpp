#ifndef TEST_H_
#define TEST_H_


#include<utility>
#include<stdexcept>
#include<iostream>

namespace nsp {

	template<typename T>
	class Share_ptr {
		T* pvalue = nullptr;
		unsigned* pcount = nullptr;
		void chk(void) noexcept(false);

	public:
		Share_ptr() noexcept = default;
		Share_ptr(T* pv)noexcept(false) try :
			pvalue(pv), pcount(new unsigned(1)){}
		catch (const std::bad_alloc& err) {
			std::cerr << err.what() << std::endl;
		}
		Share_ptr(const Share_ptr& sp)noexcept;
		Share_ptr(Share_ptr&& sp)noexcept;
		~Share_ptr()noexcept;

		T& operator*() noexcept(false);
		const T& operator*() const noexcept(false);
		T* operator->() noexcept(false);
		const T* operator->() const noexcept(false);

		unsigned use_count(void) const noexcept;
	};

	/*------------------类成员的定义-------------------*/

	template<typename T>
	inline void Share_ptr<T>::chk(void) noexcept(false) {
		if (!pvalue) throw std::runtime_error("Nothing to point");
	}

	template<typename T>
	inline Share_ptr<T>::Share_ptr(const Share_ptr& sp)noexcept :
		pvalue(sp.pvalue), pcount(sp.pcount) {
		if (pvalue)++* pcount;
	}

	template<typename T>
	inline Share_ptr<T>::Share_ptr(Share_ptr&& sp)noexcept :
		pvalue(std::move(sp.pvalue)), pcount(std::move(sp.pcount)) {
		sp.pvalue = nullptr; sp.pcount = nullptr;
	}

	template<typename T>
	Share_ptr<T>::~Share_ptr() noexcept {
		if (pvalue && -- * pcount == 0) {
			delete pvalue;
			delete pcount;
		}
		pvalue = nullptr; pcount = nullptr;
	}

	template<typename T>
	T& Share_ptr<T>::operator*()noexcept(false) {
		chk();
		return *pvalue;
	}

	template<typename T>
	const T& Share_ptr<T>::operator*() const noexcept(false) {
		chk();
		return *pvalue;
	}

	template<typename T>
	T* Share_ptr<T>::operator->() noexcept(false) {
		return &this->operator*();
	}

	template<typename T>
	const T* Share_ptr<T>::operator->() const noexcept(false) {
		return &this->operator*();
	}

	template<typename T>
	unsigned Share_ptr<T>::use_count(void) const noexcept {
		return pvalue ? *pcount : 0;
	}
}

#endif
