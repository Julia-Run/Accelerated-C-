//
// Created by dora on 11/18/22.
//

#ifndef CPP_TEMPLATE_VEC_H
#define CPP_TEMPLATE_VEC_H

#include <cstddef>
#include <memory>

template<class T>
class vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
//    typedef T& reference;
    typedef const T &const_reference;

    // constructor
    vec() { creat(); }

    explicit vec(size_type n, const_reference val = T()) { creat(n, val); } // include default

    // copy_constructor
    vec(iterator a, iterator b) { creat(a, b); }

    //de_constructor
    ~vec() { unCreat(); }

    //operator =
    vec &operator=(const vec &);

    // []
    T &operator[](size_type i) { return data[i]; }

    const T &operator[](size_type i) const { return data[i]; }

    size_type size() { return avail - data; }

    iterator begin() { return data; }

    iterator end() { return avail; }

    const_iterator begin() const { return data; }

    const_iterator end() const { return avail; }

    // pushback
    void pushBack(const T &val) {
        if (avail == limit) grow();
        backAdd(val);
    }


private:
    iterator data, avail, limit;
    std::allocator<T> alloc;

    void creat();

    void creat(size_type, const T & = T());

    void creat(iterator, iterator);

    void unCreat();

    void grow();

    void backAdd(const T &);
};

#include "vec_templeteFunc.h"  // including all template functions which cannot be put in a .cpp file !! ---> if so, it will cause undefined reference

#endif //CPP_TEMPLATE_VEC_H
