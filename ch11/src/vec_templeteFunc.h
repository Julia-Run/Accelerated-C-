//
// Created by dora on 11/18/22.
//

#include "vec.h"

template<class T>
void vec<T>::grow() {
    size_type newLen = std::max(2 * (limit - data), ptrdiff_t(1));
    iterator newData = alloc.allocate(newLen);
    iterator newAvail = std::uninitialized_copy(data, avail, newData);
    unCreat();
    data = newData;
    avail = newAvail;
    limit = newData + newLen;
}

template<class T>
void vec<T>::creat() { data = avail = limit = nullptr; }

template<class T>
void vec<T>::creat(size_type n, const T &val) {  // default val not need
    data = alloc.allocate(n); // start
    avail = limit = data + n;
    std::uninitialized_fill(data, avail, val);
}

template<class T>
void vec<T>::creat(iterator b, iterator e) {
    data = alloc.allocate(e - b);
    limit = avail = std::uninitialized_copy(b, e, data);
}

template<class T>
void vec<T>::unCreat() {
    if (data!=nullptr) {
        iterator b = avail;
        while (b != data) alloc.destroy(--b);
        alloc.deallocate(data, limit - data);
    }
    data = avail = limit = nullptr;
}



template<class T>
void vec<T>::backAdd(const T &val) {
    alloc.construct(avail++, val);
}

template<class T>
vec<T> &vec<T>::operator=(const vec<T> &v) {
    if (this != v) {
        unCreat();
        creat(v.begin(), v.end());
    }
    return *this;
}