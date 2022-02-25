//
// Created by dora on 22/2/2022.
//

#include <stdexcept>
#include "median.h"
#include "grade.h"
#include "student _info.h"

using namespace std;


double grade(double mid, double final, double hw) {
    return mid * 0.2 + final * 0.2 + hw * 0.6;
}

double grade(double mid, double final, const vector<double> &hw) {
    // 02. The const qualified parameter 'hw' is copied for each invocation; consider making it a reference
    vector<double>::size_type i = hw.size();
    if (i == 0) throw domain_error("No homework grades!");
    return grade(mid, final, median(hw));
}

double grade(const student_info &oneStudent) {
    return grade(oneStudent.midterm, oneStudent.final, oneStudent.homework);
}