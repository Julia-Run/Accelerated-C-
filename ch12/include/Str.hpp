//
// Created by dora on 11/21/22.
//

#ifndef CPP_TEMPLATE_STR_HPP
#define CPP_TEMPLATE_STR_HPP

#include <iostream>
#include "vec.hpp"
#include <cstring>
#include <algorithm>

class Str {
    friend std::istream &operator>>(std::istream &is, Str &s);

public:
    typedef size_t size_type;

    size_type size() { return data.size(); }

    Str() {};

    Str(const size_type n, const char &c) : data(n, c) {}; // see pos of data
    Str(const char *c) {
        std::copy(c, c + std::strlen(c), std::back_inserter(data));
    }  // auto - transform, required value_type && push_back
    template<class In>
    Str(In a, In b) {
        std::copy(a, b, std::back_inserter(data));
    }

    Str &operator+=(const Str &b) {
        std::copy(b.data.begin(), b.data.end(), std::back_inserter(data));
        return *this;
    }

    char &operator[](size_type i) { return data[i]; }

    const char &operator[](size_type i) const { return data[i]; }

private:
    vec<char> data;
};


std::istream &operator>>(std::istream &is, Str &s) {
//    s.data.clear();
    char c;
    while (is.get(c) && isspace(c));
    // c == char;
    if (is) {
        do s.data.push_back(c);
        while (is.get(c) && !isspace(c));
        // c is space;
        if (is) is.unget();
    }
    return is;
}

std::ostream &operator<<(std::ostream &ot, Str &s) {
    for (Str::size_type i = 0; i != s.size(); ++i) {
        ot << s[i];
    }
    return ot;
}

Str operator+(const Str &a, const Str &s) {
    Str r(a);
    r += s;
    return r;
}


#endif //CPP_TEMPLATE_STR_HPP
