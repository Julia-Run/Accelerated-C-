//
// Created by dora on 12/2/22.
//

#ifndef CPP_TEMPLATE_HANDLECOUNT_HPP
#define CPP_TEMPLATE_HANDLECOUNT_HPP

#include <stdexcept>
#include "vec.hpp"

template<class T>
class HandleCount {
private:
    T *ptr;
    std::size_t * cnt;
public:
    void make_unique(){
        if (*cnt!=1){
            --*cnt;
            cnt = new size_t(1);
            ptr = ptr ? clone(*this) : 0;
        }
    }

    HandleCount() : ptr(0), cnt(new std::size_t(1)) {}

    HandleCount(const HandleCount &h) : ptr(h.ptr), cnt(h.cnt){
        ++*cnt;
    }

    HandleCount(T *t) : ptr(t), cnt(new std::size_t(1)) {}

    ~HandleCount() {
        if (--*cnt==0){
            delete ptr;
            delete cnt;
        }
    }

    HandleCount &operator=(const HandleCount &h) {
        // copy h to here
        if (h.cnt) {
            ++*h.cnt;
            if (--*cnt == 0) {
                delete ptr;
                delete cnt;
            }
            cnt = h.cnt;
            ptr = h.ptr;
        }
        return *this;
    }

    T &operator*() const {
        if (ptr) return *ptr;
        throw std::runtime_error("Null Object!");
    }

    T *operator->() const{
        if (ptr) return ptr;
        throw std::runtime_error("Null Object!");
    }

    operator bool() const { return ptr; }
};

template <class T >
T* clone(const T* p){
    if (p){
        return p->clone();
    }
}

template<>
vec<char>* clone(const vec<char>* p){
    return new vec<char>(*p);
}

#endif //CPP_TEMPLATE_HANDLECOUNT_HPP
