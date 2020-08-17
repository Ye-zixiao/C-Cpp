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
		Share_ptr(T* pv)noexcept(false) try:
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
}

#endif
