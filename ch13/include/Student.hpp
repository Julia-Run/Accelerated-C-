//
// Created by dora on 11/30/22.
//

#ifndef CPP_TEMPLATE_STUDENT_HPP
#define CPP_TEMPLATE_STUDENT_HPP

#include "Core.hpp"
#include "Grad.hpp"
#include <iostream>

class Student{
private:
    Core* cp;
public:
    Student(): cp(0) { }
    Student(std::istream & is): cp(0) { read(is);}
    Student(const Student & s):cp(0){
        if (s.cp) cp = s.cp->clone();
    }

    Student& operator=(const Student &s) {
        if (this != &s){
            delete cp;
            if (s.cp) cp = s.cp->clone();
            else cp = 0;
        }
        return *this;
    }

    std::istream& read(std::istream & is){
        delete cp;
        char ch;
        is >> ch;
        if (ch=='U') cp = new Core(is);
        else cp = new Grad(is);
        return is;
    }

    void read(std::string & s){
        if (s[0]=='U') cp = new Core;
        else cp = new Grad;
        cp->read(s);
    }

    double grade(){
        if (cp) return cp->grade();
        throw std::runtime_error("Un_initialized object");
    }

    std::string name(){
        if (cp) return cp->name();
        throw std::runtime_error("Un_initialized object");
    }

    static bool compare(const Student &s1, const Student &s2){
        return s1.cp->name() < s2.cp->name();
    }

};

#endif //CPP_TEMPLATE_STUDENT_HPP
