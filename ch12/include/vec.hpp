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
    typedef T value_type;

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
    void push_back(const T &val) {
        if (avail == limit) grow();
        backAdd(val);
    }

//    void clear(){
//        iterator t = data;
//        if (data){
//            while (t!=avail) {
// //                it = 0;
//                alloc.destroy(t++);
//            }
// //        while (it!=avail) alloc.destroy(it);
//        }
//        data = avail = limit = 0;
//    }
    void clear(){
        if (data){
            while (data!=avail) {
                alloc.destroy(data++);
            }
        }
        data = avail = limit = 0;
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

#endif //CPP_TEMPLATE_VEC_H
