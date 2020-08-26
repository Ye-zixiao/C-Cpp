#ifndef _STRVEC_H_
#define _STRVEC_H_

#include<iostream>
#include<string>
#include<memory>
#include<utility>
#include<stdexcept>


class StrVec {
public:
    using size_type = size_t;

    StrVec() {}
    StrVec(std::initializer_list<std::string> sl);
    StrVec(const std::string* b, const std::string* e);
    StrVec(const StrVec& item);
    ~StrVec();

    StrVec& operator=(const StrVec& rhs);
    std::string& operator[](size_type n) {
        if (n < 0 || n >= size())
            throw std::out_of_range("Out of Range");
        return *(begin_iter + n);
    }

    void push_back(const std::string& str);
    void pop_back(void);
    size_type size(void) const;
    size_type capacity(void) const;
    void resize(size_type n);
    void reserve(size_type n);
    void shrink_to_fit(void);
    bool empty(void) const;
    void clear(void);

    std::string* begin(void) const {
        return begin_iter;
    }
    std::string* end(void) const {
        return construct_end_iter;
    }


private:
    void free(void);																	//释放当前begin_iter指向的动态内存空间
    std::pair<std::string*, std::string*> alloc_n_cpy(const std::string* b,const std::string* e);	//将指定的b-e范围内的元素拷贝到当前的动态原始内存（刚由alloc分配所得）中
    void move_mem(size_type n);                                                         //数据迁移函数，n>=当前的size
    void reallocate(void);																//将当前旧内存上的元素转移到新分配更大动态内存上//要是默认修改两倍，不默认设定则为为指定容量
    void chk_n_alloc(void) {															//检查当前的动态内存是否足量
        if (construct_end_iter == end_iter)reallocate();
    }

    static std::allocator<std::string> alloc;
    std::string* begin_iter = nullptr;
    std::string* construct_end_iter = nullptr;
    std::string* end_iter = nullptr;
};



#endif
