#ifndef _HASPTR_H_
#define _HASPTR_H_

#include<iostream>
#include<string>
#include<memory>
#include<utility>
#include<stdexcept>

class HasPtr {
	friend std::string& operator*(const HasPtr& item);
	friend void swap(HasPtr& lhs, HasPtr& rhs);
public:
	HasPtr() = default;
	HasPtr(std::string* ps):
		pstr(ps),use(new size_t(1)){}

	//�������Ƴ�Ա
	HasPtr(const HasPtr& item);
	HasPtr(HasPtr&& item)noexcept;
	~HasPtr();

	HasPtr& operator=(HasPtr rhs);//���������������汾�ĸ�ֵ�����
	//HasPtr& operator=(const HasPtr& rhs);
	HasPtr& operator=(HasPtr&& rhs)noexcept;

	bool expired(void) const {
		return !pstr;
	}

private:
	void free(void);
	std::string* pstr = nullptr;
	size_t* use = nullptr;
};

extern std::string& operator*(const HasPtr& item);
extern void swap(HasPtr& lhs, HasPtr& rhs);

#endif
