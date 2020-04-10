#ifndef _STRING_H_
#define _STRING_H_

#include<iostream>
#include<utility>
#include<memory>
#include<iterator>
#include<algorithm>

class String {
    friend std::ostream& operator<<(std::ostream& os, const String& str);
public:
    using size_type = size_t;

    String(const char* cp = "");
    ~String();

    /*��������*/
    String(const String& item);
    String& operator=(const String& item);

    /*�ƶ�����*/
    String(String&& item)noexcept;
    String& operator=(String&& item)noexcept;


    char& operator[](size_type n);
    String operator+(const String& str);

    size_type size(void) const;
    size_type capacity(void) const;
    void reverse(size_type n);
    bool empty(void) const;
    void shrink_to_fit(void);
    void clear(void);
    void push_back(const char& ch);
    void pop_back(void);
    void resize(size_type n);

    char* begin(void)const {
        return begin_iter;
    }
    char* end(void)const {
        return construct_end_iter;
    }

private:
    void free(void);
    void move_mem(size_type n);//����ȷ��n���ڵ�ǰ��size()
    void range_initialize(const char*, const char*);//�·���һ���ڴ棬����һ�����з�Χ�е�Ԫ�ؿ������ˣ�Ȼ���ͷ�ԭ�����ڴ�ռ䣬�����ڿ������졢������ֵ��������б��ʼ��
    void chk_n_alloc(void);
    void reallocate(void);
    std::pair<char*, char*> alloc_n_cpy(const char* b, const char* e);

    static std::allocator<char> alloc;
    char* begin_iter = nullptr;
    char* construct_end_iter = nullptr;
    char* end_iter = nullptr;
};

extern std::ostream& operator<<(std::ostream& os, const String& str);

#endif
