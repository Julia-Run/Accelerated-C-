//
// Created by dora on 8/9/2022.
//
#include <stdexcept>
#include "medium.hpp"
#include "grade.hpp"
#include "student_info.hpp"

using namespace std;

double grade(double m, double f, double h) {
    return m * 0.3 + f * 0.3 + h * 0.4;
}

double grade(double m, double f, const vector<double> &hw) {
    if (hw.size() == 0) throw domain_error("NO homework grade");
    return grade(m, f, medium(hw));
}

double grade(const Student_info &a) {
    return grade(a.midterm, a.final, a.hw);
}
