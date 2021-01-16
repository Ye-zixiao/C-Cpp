#include"StrVec.h"
#include<algorithm>
//#define DEBUG
std::allocator<std::string> StrVec::alloc;

/*-----------------------һ�����-----------------------*/
StrVec::size_type
StrVec::size(void) const {
    return begin_iter ? construct_end_iter - begin_iter : 0;
}

StrVec::size_type
StrVec::capacity(void) const {
    return begin_iter ? end_iter - begin_iter : 0;
}

bool
StrVec::empty(void) const {
    return !size();
}

void
StrVec::reserve(size_type n) {
    if (n > capacity()) {
        move_mem(n);
    }
}

void
StrVec::push_back(const std::string& str) {
    chk_n_alloc();
    alloc.construct(construct_end_iter++, str);
}

void
StrVec::push_back(std::string&& str) {
    chk_n_alloc();
    alloc.construct(construct_end_iter++, std::move(str));
}

void
StrVec::pop_back(void) {
    if (!empty())
        alloc.destroy(--construct_end_iter);
}

void
StrVec::shrink_to_fit(void) {
    if (capacity() > size()) {
        move_mem(size());
    }
}

void
StrVec::resize(size_type n,const std::string&str) {
    if (n >= size()) {
        if (n > capacity())
            move_mem(n * 2);
        while (construct_end_iter != begin_iter + n)
            alloc.construct(construct_end_iter++, str);
    }
    else {
        while (construct_end_iter != begin_iter + n)
            alloc.destroy(--construct_end_iter);
    }
}

void
StrVec::clear(void) {
    auto clear_size = size();
    for (size_t i = 0; i < clear_size; ++i)
        alloc.destroy(--construct_end_iter);
}

/*-----------------------�������Ƴ�Ա���������캯��-------------------*/
StrVec::StrVec(std::initializer_list<std::string> sl) {//��д���򲻺õ�ϰ�߾����ظ�������ͬ�Ĵ���
    range_initialize(sl.begin(), sl.end());
}

StrVec::StrVec(size_type n, const std::string& str) :
    begin_iter(alloc.allocate(n)), end_iter(begin_iter + n), construct_end_iter(begin_iter) {
    while (construct_end_iter != end_iter)
        alloc.construct(construct_end_iter++, str);
}

StrVec::StrVec(const std::string* b, const std::string* e) {
    auto ret = alloc_n_cpy(b, e);
    begin_iter = ret.first;
    construct_end_iter = ret.second;
    end_iter = ret.second;
}

StrVec::~StrVec() {
    free();
}

StrVec::StrVec(const StrVec& item) {
    range_initialize(item.begin(), item.end());
}

StrVec&
StrVec::operator=(const StrVec& item) {
    range_initialize(item.begin(), item.end());
    return *this;
}

StrVec::StrVec(StrVec&& item)noexcept :
    begin_iter(std::move(item.begin_iter)), construct_end_iter(std::move(item.construct_end_iter)),
    end_iter(std::move(item.end_iter)) {
#ifdef DEBUG
    std::cout << "StrVec(StrVec&&)" << std::endl;
#endif
    item.begin_iter = item.construct_end_iter = item.end_iter = nullptr;
}

StrVec&
StrVec::operator=(StrVec&& item)noexcept {
#define DEBUG
#ifdef DEBUG
    std::cout << "StrVec& operator=(StrVec&&)noexcept" << std::endl;
#endif
#undef DEBUG
    if (this != &item) {
        free();
        begin_iter = std::move(item.begin_iter);
        construct_end_iter = std::move(item.construct_end_iter);
        end_iter = std::move(item.end_iter);
        item.begin_iter = item.construct_end_iter = item.end_iter = nullptr;
    }
    return *this;
}

//StrVec&
//StrVec::operator=(std::initializer_list<std::string> sl) {
//    range_initialize(sl.begin(), sl.end());
//    return *this;
//}

//StrVec&//������ʽ�����ظ�ֵ��������������ʽ��ת������+�ƶ���ֵȥ���
//StrVec::operator=(std::initializer_list<std::string> sl) {
//    *this = StrVec(sl);
//    return *this;
//}

std::string&
StrVec::operator[](size_type n) {
    return begin_iter[n];
}

const std::string&
StrVec::operator[](size_type n)const {
    return begin_iter[n];
}


/*-----------------------˽�й��ߺ���-------------------*/
//ʹ��for_each+lambda���ʽ��дfree()
void
StrVec::free(void) {
    if (begin_iter) {
        std::for_each(begin_iter, construct_end_iter, [](std::string& p) {alloc.destroy(&p); });//alloc�Ǻ������ⶨ��ľ�̬��������Ȼ������lambda���ʽ��ʹ��
        alloc.deallocate(begin_iter, end_iter - begin_iter);
    }
}
//for_each�㷨��lambda���ʽ�����б��������Ԫ�ص�����
        /*
            �ȼ��ڣ�
            for(auto iter=begin_iter;iter!=construce_end_iter;++iter)
                *iter----->[](std::string& ref){alloc.destroy(&p);}
            //for_each������������Ԫ�أ��õ����ǿ��޸ĵ���ֵ����Ȼ�������ֵ����lambda���ʽ
        */
/*ʹ�ò�ͬwhileѭ����дfree()
void
StrVec::free(void) {
    if (begin_iter) {//���begin_iter�Ƿ������ָ��һ����̬�ڴ�
        while (construct_end_iter != begin_iter)
            alloc.destroy(--construct_end_iter);
        alloc.deallocate(begin_iter, end_iter - begin_iter);
    }
}*/

std::pair<std::string*, std::string*>
StrVec::alloc_n_cpy(const std::string* b, const std::string* e) {
    auto iter = alloc.allocate(e - b);
    return { iter,std::uninitialized_copy(b,e,iter) };
}

void
StrVec::reallocate(void) {
    auto newcapacity = size() ? size() * 2 : 1;
    move_mem(newcapacity);
}

void
StrVec::move_mem(size_type n) {
    auto new_begin_iter = alloc.allocate(n);
    auto last = std::uninitialized_copy(std::make_move_iterator(begin_iter),
        std::make_move_iterator(construct_end_iter), new_begin_iter);
    free();
    begin_iter = new_begin_iter;
    construct_end_iter = last;
    end_iter = new_begin_iter + n;
}

void
StrVec::range_initialize(const std::string* b, const std::string* e) {
    auto ret = alloc_n_cpy(b, e);
    free();
    begin_iter = ret.first;
    end_iter = construct_end_iter = ret.second;
}


/*------------------------���⺯��-----------------------*/

bool
operator==(const StrVec& lhs, const StrVec& rhs) {
    if (lhs.size() != rhs.size())
        return false;
    for (decltype(lhs.size()) i = 0, size = lhs.size(); i < size; ++i)
        if (lhs[i] != rhs[i])
            return false;
    return true;
}

bool
operator!=(const StrVec& lhs,const StrVec& rhs) {
    return !(rhs == lhs);
}

bool
operator<(const StrVec& lhs, const StrVec& rhs) {
    auto mid = (lhs.size() < rhs.size() ? lhs.size() : rhs.size());
    for (StrVec::size_type i = 0; i < mid; ++i)
        if (lhs[i] < rhs[i])return true;
        else if (lhs[i] > rhs[i])return false;
    return lhs.size() < rhs.size() ? true : false;
}
