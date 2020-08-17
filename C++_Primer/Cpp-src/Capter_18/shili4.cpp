#include<iostream>
#include<memory>
#include<string>
#include<stdexcept>
#include<utility>
using namespace::std;

template<typename T>
class Shared_ptr {
	T* p = nullptr;
	size_t* pcount = nullptr;
	void chk(void) noexcept(false) {
		if (!p)throw runtime_error("Nothing to point");
	}

public:
	using size_type = size_t;

	Shared_ptr(T* pvalue)noexcept(false)try :
		p(pvalue), pcount(new size_t(1)){}
	catch (const bad_alloc& err) {
		cerr << err.what() << endl;
	}
	Shared_ptr(const Shared_ptr& sp)noexcept :
		p(sp.p), pcount(sp.pcount) {
		++pcount;
	}
	Shared_ptr(Shared_ptr&& sp)noexcept :
		p(std::move(sp.p)), pcount(std::move(sp.pcount)) {
		sp.p = nullptr;
		sp.pcount = nullptr;
	}
	~Shared_ptr()noexcept {
		if (p && -- * pcount == 0) {
			delete p;
			delete pcount;
			p = nullptr;
			pcount = nullptr;
		}
	}

	T& operator*()noexcept(false) {
		chk();
		return *p;
	}
	const T& operator*() const noexcept(false) {
		chk();
		return *p;
	}
	T* operator->()noexcept(false) {
		return &this->operator*();
	}
	const T* operator->() const noexcept(false) {
		return &this->operator*();
	}

	size_type use_count(void) const noexcept {
		return pcount ? *pcount : 0;
	}

	void reset(void) noexcept {
		if (p) {
			if (-- * pcount == 0) {
				delete pcount;
				delete p;
			}
			p = nullptr;
			pcount = nullptr;
		}
	}
};

int main(void)
{
	Shared_ptr<string> strp(new string("hello world"));
	cout << strp.use_count() << endl;
	cout << *strp << endl;

	Shared_ptr<string> strp_move = std::move(strp);
	cout << strp.use_count() << endl;
	cout << strp_move.use_count() << endl;
	cout << *strp_move << endl;


	return 0;
}
