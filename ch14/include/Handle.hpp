//
// Created by dora on 12/2/22.
//

#ifndef CPP_TEMPLATE_HANDLE_HPP
#define CPP_TEMPLATE_HANDLE_HPP

#include <stdexcept>

template<class T>
class Handle {
private:
    T *ptr;
public:
    Handle() : ptr(0) {}

    Handle(const Handle &h) {
        // copy h to here
        if (h.ptr) {
            ptr = h->clone();
        }
    }

    Handle(const T *t) : ptr(t) {}

    Handle &operator=(const Handle &h) {
        if (&h != this) {
            delete ptr;
            ptr = h.ptr ? h->clone() : 0;
        }
        return *this;
    }

    T &operator*() {
        if (ptr) return *ptr;
        throw std::runtime_error("Null Object!");
    }

    T *operator->() {
        if (ptr) return ptr;
        throw std::runtime_error("Null Object!");
    }

    operator bool() { return ptr; }
};

#endif //CPP_TEMPLATE_HANDLE_HPP
