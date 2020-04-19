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

    //����������
    StrVec(const StrVec& item);
    StrVec& operator=(const StrVec& rhs);
    //�ƶ�������
    StrVec(StrVec&& item)noexcept;
    StrVec& operator=(StrVec&& item)noexcept;

    //StrVec& operator=(std::initializer_list<std::string> sl);//��������һ��ת�����캯��������һ����ʱ�����Ȼ�����ƶ���ֵ����������ƶ�����
    std::string& operator[](size_type n);
    const std::string& operator[](size_type n) const;

    void push_back(const std::string& str);
    void push_back(std::string&& str);
    void pop_back(void);
    size_type size(void) const;
    size_type capacity(void) const;
    void resize(size_type n, const std::string& str = "");
    void reserve(size_type n);//��Ʋ��ԣ�ֻ�����ó�>=��ǰ��ʵsize
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
    /*    �����������Ҫ��дʲô���Ĺ��ߺ���
    �����޷��ǣ�1����̬�ڴ�ֻ������������ڴ��ƶ������----move_mem��reallocate��chk_n_alloc
                2����̬�ڴ濽�������ƶ�����������˿������һ����Լ��������Լ��������-----alloc_n_cpy��range_initialize
                3����Ҫ�ͷ��ڴ�-----free
    */
    
    void free(void);																	//�ͷŵ�ǰbegin_iterָ��Ķ�̬�ڴ�ռ�
    std::pair<std::string*, std::string*> alloc_n_cpy(const std::string* b,const std::string* e);	//��ָ����b-e��Χ�ڵ�Ԫ�ؿ�������ǰ�Ķ�̬ԭʼ�ڴ棨����alloc�������ã���
    void range_initialize(const std::string* b, const std::string* e);                  //�·����ڴ������һ�����еĿ�����Ȼ���ͷ�ԭ�ڴ棬������ָ�롣�����ڿ������졢�б��ʼ����������ֵ�����
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
