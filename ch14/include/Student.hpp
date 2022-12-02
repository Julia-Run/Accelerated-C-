//
// Created by dora on 12/2/22.
//

#ifndef CPP_TEMPLATE_STUDENT_HPP
#define CPP_TEMPLATE_STUDENT_HPP

#include "HandleCount.hpp"
#include "Core.hpp"
#include "Grad.hpp"

class Student {
private:
    HandleCount<Core> p;
public:
    Student() = default;

    explicit Student(const std::string &s) { read(s); }

    void read(const std::string &s) {
        if (s[0] == 'U') p = new Core(s);
        else p = new Grad(s);
    }

    std::string getName() const {
        if (p) return p->getName();
        return "NULL";
    }

    double grade() {
        if (p) return p->grade();
        return -1;
    }

    static bool compare(const Student &s1, const Student &s2) {
        return s1.getName() < s2.getName();
    }
};

#endif //CPP_TEMPLATE_STUDENT_HPP
