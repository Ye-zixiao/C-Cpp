#include"String.h"
//#define DEBUG
//#define CTRDEBUG
std::allocator<char> String::alloc;

/*--------------------一般操作-------------------------------*/

const char*
String::c_str(void)const {
    return begin_iter;
}

String::size_type
String::size(void) const{
    return begin_iter ? construct_end_iter - begin_iter : 0;
}

String::size_type
String::capacity(void) const {
    return begin_iter ? end_iter - begin_iter : 0;
}

bool
String::empty(void) const {
    return !size();
}

void
String::clear(void) {
    if (begin_iter)
        while (construct_end_iter != begin_iter)
            alloc.destroy(--construct_end_iter);
}

void
String::reverse(size_type n) {
    if (n > capacity())
        move_mem(n);
}

void
String::shrink_to_fit(void) {
    move_mem(size());
}

void
String::push_back(const char& ch) {
#ifdef DEBUG
    std::cout << "push_back(const char&ch)" << std::endl;
#endif
    chk_n_alloc();
    alloc.construct(construct_end_iter++, ch);
}

void
String::pop_back(void) {
    if (!empty())
        alloc.destroy(--construct_end_iter);
}

void
String::resize(size_type n) {
    if (n > size()) {
        if (n > capacity())
            move_mem(n);
        auto delta_size = n - size();
        for (size_type i = 0; i < delta_size; ++i)
            alloc.construct(construct_end_iter++, ' ');
    }
    else {
        auto delta_size = size() - n;
        for (size_type i = 0; i < delta_size; ++i)
            alloc.destroy(--construct_end_iter);
    }
}

char&
String::operator[](size_type n) {
    return begin_iter[n];
}

const char&
String::operator[](size_type n) const {
    return begin_iter[n];
}

String&
String::operator+=(const String& item) {
#ifdef CTRDEBUG
    std::cout << "String& operator+=(const String&)" << std::endl;
#endif
    const auto new_begin = alloc.allocate(size() + item.size());
    auto second_p = std::uninitialized_copy(begin_iter, construct_end_iter, new_begin);
    auto last_p = std::uninitialized_copy(item.begin(), item.end(), second_p);
    free();
    begin_iter = new_begin;
    construct_end_iter = end_iter = last_p;
    return *this;
}

/*--------------------------拷贝控制成员和其他重要的成员------------------------*/
String::String(const char* cp) {
#ifdef DEBUG
    std::cout << "String(const char*)" << std::endl;
#endif
    while (*cp)
        push_back(*cp++);
}

String::~String() {
    free();
}

String::String(const String& str) {
#ifdef DEBUG
    std::cout << "String(const String&str)" << std::endl;
#endif
    range_initialize(str.begin(), str.end());
}

String::String(String&& item) noexcept :
    begin_iter(std::move(item.begin_iter)), construct_end_iter(std::move(item.construct_end_iter)),
    end_iter(std::move(item.end_iter)) {
#ifdef DEBUG
    std::cout << "String(String&&)noexcept" << std::endl;
#endif
    item.begin_iter = item.construct_end_iter = item.end_iter = nullptr;
}

String&
String::operator=(const String& str) & {
#ifdef DEBUG
    std::cout << "String& operator=(const String&str)" << std::endl;
#endif
    range_initialize(str.begin(), str.end());
    return *this;
}

String&
String::operator=(String&& item) & noexcept {
#ifdef DEBUG
    std::cout << "String& operator=(String&&)noexcept" << std::endl;
#endif
    if (this != &item) {
        free();
        begin_iter = item.begin_iter;
        construct_end_iter = item.construct_end_iter;
        end_iter = item.end_iter;
        item.begin_iter = item.construct_end_iter = item.end_iter = nullptr;
    }
    return *this;
}

/*--------------------------私有工具函数------------------------*/
void
String::free(void) {
    if (begin_iter) {
#ifdef DEBUG
        std::cout << "free(): " << (void*)begin_iter << std::endl;
#endif
        std::for_each(begin_iter, construct_end_iter, [](char& ch) {alloc.destroy(&ch); });
        alloc.deallocate(begin_iter, end_iter - begin_iter);
    }
}

void
String::move_mem(size_type n) {
    auto ret = alloc.allocate(n);
    auto last = std::uninitialized_copy(std::make_move_iterator(begin_iter), 
        std::make_move_iterator(construct_end_iter),ret);
    free();
    begin_iter = ret;
    construct_end_iter = last;
    end_iter = ret + n;
}

/*auto src_memp = begin_iter;
for (size_type i = 0; i < size(); ++i)
    alloc.construct(dest_memp++, std::move(*src_memp++));*/

void
String::chk_n_alloc(void) {
    if (construct_end_iter == end_iter)
        reallocate();
}

void
String::reallocate(void) {
    auto newcapacity = size() ? size() * 2 : 1;
    move_mem(newcapacity);
}

std::pair<char*, char*>
String::alloc_n_cpy(const char* b, const char* e) {
    auto ret = alloc.allocate(e - b);
    return { ret,std::uninitialized_copy(b,e,ret) };
}

void
String::range_initialize(const char* b, const char* e) {
    auto ret = alloc_n_cpy(b, e);
    free();
    begin_iter = ret.first;
    construct_end_iter = end_iter = ret.second;
}

/*--------------------------类外函数------------------------*/

std::ostream& operator<<(std::ostream& os, const String& str) {
    std::for_each(str.begin(), str.end(), [&os](char ch) {os << ch; });
    return os;
}

bool
operator==(const String& lhs, const String& rhs) {
    if (lhs.size() != rhs.size())
        return false;
    for (decltype(lhs.size()) i = 0, size = lhs.size(); i < size; ++i)
        if (lhs[i] != rhs[i])
            return false;
    return true;
}

bool 
operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

bool 
operator<(const String& lhs, const String& rhs) {
    auto mid = (lhs.size() < rhs.size() ? lhs.size() : rhs.size());
    for (String::size_type i = 0; i < mid; ++i)
        if (lhs[i] < rhs[i])return true;
        else if (lhs[i] > rhs[i])return false;
    return lhs.size() < rhs.size() ? true : false;
}

String 
operator+(const String& lhs, const String& rhs) {
    String temp(lhs);
    temp += rhs;
    return temp;
}