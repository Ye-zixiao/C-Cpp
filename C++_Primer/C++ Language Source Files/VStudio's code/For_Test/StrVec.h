#ifndef _STRVEC_H_
#define _STRVEC_H_

#include<iostream>
#include<string>
#include<memory>
#include<utility>
#include<stdexcept>


class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
public:
    using size_type = size_t;

    StrVec() {}
    StrVec(std::initializer_list<std::string> sl);
    StrVec(size_type n, const std::string& str=std::string());
    StrVec(const std::string* b, const std::string* e);
    ~StrVec();

    //拷贝操作：
    StrVec(const StrVec& item);
    StrVec& operator=(const StrVec& rhs);
    //移动操作：
    StrVec(StrVec&& item)noexcept;
    StrVec& operator=(StrVec&& item)noexcept;

    //StrVec& operator=(std::initializer_list<std::string> sl);//这里我让一个转换构造函数创建出一个临时类对象，然后用移动赋值运算符进行移动操作
    std::string& operator[](size_type n);
    const std::string& operator[](size_type n) const;

    void push_back(const std::string& str);
    void push_back(std::string&& str);
    void pop_back(void);
    size_type size(void) const;
    size_type capacity(void) const;
    void resize(size_type n, const std::string& str = "");
    void reserve(size_type n);//设计策略：只能设置成>=当前真实size
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
    /*    需求决定我们要编写什么样的工具函数
    需求无非是：1、动态内存只能增长而造成内存移动的情况----move_mem、reallocate、chk_n_alloc
                2、动态内存拷贝，不移动的情况（别人拷贝给我或者自己拷贝给自己的情况）-----alloc_n_cpy、range_initialize
                3、需要释放内存-----free
    */
    
    void free(void);																	//释放当前begin_iter指向的动态内存空间
    std::pair<std::string*, std::string*> alloc_n_cpy(const std::string* b,const std::string* e);	//将指定的b-e范围内的元素拷贝到当前的动态原始内存（刚由alloc分配所得）中
    void range_initialize(const std::string* b, const std::string* e);                  //新分配内存接收另一个序列的拷贝，然后释放原内存，并更新指针。适用于拷贝构造、列表初始化、拷贝赋值运算符
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
