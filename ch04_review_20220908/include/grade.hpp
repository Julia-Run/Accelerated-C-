//
// Created by dora on 8/9/2022.
//

#ifndef CPP_TEMPLATE_GRADE_HPP
#define CPP_TEMPLATE_GRADE_HPP

#include <vector>
#include "student_info.hpp"

double grade(double, double, double);

double grade(double, double, const std::vector<double> &);

double grade(const Student_info &);

#endif //CPP_TEMPLATE_GRADE_HPP
