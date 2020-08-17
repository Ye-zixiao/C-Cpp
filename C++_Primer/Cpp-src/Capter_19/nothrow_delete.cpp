#include<iostream>
#include<memory>
#include<new>

/*
 *关于nothrow delete的相关链接：
 *https://stackoverflow.com/questions/59369568/overloading-the-nothrow-version-of-new-and-delete?r=SearchResults
 *
 */

struct A {
    A() {
        throw "bahh";
    }
};

void operator delete(void* ptr) noexcept {
    std::cout << "normal delete" << std::endl;
    free(ptr);
}

void operator delete(void* ptr, const std::nothrow_t&) noexcept {
    std::cout << "nothrow delete" << std::endl;
    free(ptr);
}

int main() {
    std::cout << "calling new A" << std::endl;
    try {
        new A(); // prints: normal delete
    }
    catch (const char* s) {
        std::cout << s << std::endl; // bahh
    }

    std::cout << "calling new(std::nothrow) A" << std::endl;
    try {
        new(std::nothrow) A(); // prints: nothrow delete
    }
    catch (const char* s) {
        std::cout << s << std::endl; // bahh
    }
}
