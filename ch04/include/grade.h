//
// Created by dora on 22/2/2022.
//

#ifndef CPP_TEMPLATE_GRADE_H
#define CPP_TEMPLATE_GRADE_H

#include <vector>
#include "student _info.h"

double grade(double, double, double);

double grade(double, double, std::vector<double> &);  // 01.use cite
//const-qualification of parameters only has an effect in function definitions
double grade(const student_info &);

#endif //CPP_TEMPLATE_GRADE_H
