//
// Created by dora on 8/9/2022.
//

#ifndef CPP_TEMPLATE_STUDENT_INFO_HPP
#define CPP_TEMPLATE_STUDENT_INFO_HPP

#include <string>
#include <vector>
#include <iostream>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> hw;
};

bool compare(const Student_info &, const Student_info &);

std::istream &read(std::istream &, Student_info &);

std::istream &read_hw(std::istream &, std::vector<double> &);

#endif //CPP_TEMPLATE_STUDENT_INFO_HPP
