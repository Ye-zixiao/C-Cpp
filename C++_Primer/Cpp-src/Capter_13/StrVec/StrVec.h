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
    void free(void);																	//�ͷŵ�ǰbegin_iterָ��Ķ�̬�ڴ�ռ�
    std::pair<std::string*, std::string*> alloc_n_cpy(const std::string* b,const std::string* e);	//��ָ����b-e��Χ�ڵ�Ԫ�ؿ�������ǰ�Ķ�̬ԭʼ�ڴ棨����alloc�������ã���
    void move_mem(size_type n);                                                         //����Ǩ�ƺ�����n>=��ǰ��size
    void reallocate(void);																//����ǰ���ڴ��ϵ�Ԫ��ת�Ƶ��·������̬�ڴ���//Ҫ��Ĭ���޸���������Ĭ���趨��ΪΪָ������
    void chk_n_alloc(void) {															//��鵱ǰ�Ķ�̬�ڴ��Ƿ�����
        if (construct_end_iter == end_iter)reallocate();
    }

    static std::allocator<std::string> alloc;
    std::string* begin_iter = nullptr;
    std::string* construct_end_iter = nullptr;
    std::string* end_iter = nullptr;
};



#endif
