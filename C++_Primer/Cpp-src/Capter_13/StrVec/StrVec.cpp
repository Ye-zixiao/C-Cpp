#include"StrVec.h"

std::allocator<std::string> StrVec::alloc;

/*-----------------------------���Ա��������---------------------------------------------
*�����ƣ�StrVec
*/

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
StrVec::free(void) {
    if (begin_iter) {//���begin_iter�Ƿ������ָ��һ����̬�ڴ�
        while (construct_end_iter != begin_iter)
            alloc.destroy(--construct_end_iter);
        alloc.deallocate(begin_iter, end_iter - begin_iter);
    }
}

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
StrVec::resize(size_type n) {
    if (n >= size()) {
        if (n > capacity())
            move_mem(n);
        const auto delta_size = n - size();
        for (size_t i = 0; i < delta_size; ++i)
            alloc.construct(construct_end_iter++, "");
    }
    else {
        const auto delta_size = n - size();
        for (size_t i = 0; i < delta_size; ++i)
            alloc.destroy(--construct_end_iter);
    }
}

StrVec::StrVec(std::initializer_list<std::string> sl) {
    auto ret = alloc_n_cpy(sl.begin(), sl.end());
    begin_iter = ret.first;
    construct_end_iter = ret.second;
    end_iter = ret.second;
}

StrVec::~StrVec() {
    free();
}

StrVec::StrVec(const StrVec& item) {
    auto ret = alloc_n_cpy(item.begin(), item.end());
    begin_iter = ret.first;
    construct_end_iter = ret.second;
    end_iter = ret.second;
}

StrVec&
StrVec::operator=(const StrVec& item) {
    auto ret = alloc_n_cpy(item.begin(), item.end());
    free();
    begin_iter = ret.first;
    construct_end_iter = ret.second;
    end_iter = ret.second;
    return *this;
}

void
StrVec::clear(void) {
    auto clear_size = size();
    for (size_t i = 0; i < clear_size; ++i)
        alloc.destroy(--construct_end_iter);
}

void
StrVec::move_mem(size_type n) {
    const auto new_begin_iter = alloc.allocate(n);
    auto dest_memp = new_begin_iter;
    auto src_memp = begin_iter;
    for (size_t i = 0; i < size(); ++i)
        alloc.construct(dest_memp++, std::move(*src_memp++));
    free();
    begin_iter = new_begin_iter;
    construct_end_iter = dest_memp;
    end_iter = new_begin_iter + n;
}

StrVec::StrVec(const std::string* b, const std::string* e) {
    auto ret = alloc_n_cpy(b, e);
    begin_iter = ret.first;
    construct_end_iter = ret.second;
    end_iter = ret.second;
}


//const auto new_begin_iter = alloc.allocate(newcapacity);
   //auto dest_memp = new_begin_iter;
   //auto src_memp = begin_iter;
   ////����ԭ��̬�ڴ��ϵ����ݵ��¶�̬�ڴ��Ǩ�ƣ�ת�Ƶ�ʱ��һ��Ҫ��¼���ڴ����ָ�������ѹ����һԪ�ص�ָ��
   //for (size_t i=0;i<size();++i)
   //    alloc.construct(dest_memp++, std::move(*src_memp++));
   //free();
   ////�������ڵ�ָ��
   //begin_iter = new_begin_iter;
   //construct_end_iter = dest_memp;
   //end_iter = new_begin_iter + newcapacity;
