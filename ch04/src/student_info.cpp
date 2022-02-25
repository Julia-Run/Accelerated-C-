//
// Created by dora on 22/2/2022.
//
#include "student _info.h"

using namespace std;

istream &read_hw(istream &hwIn, vector<double> &hw) {
    if (hwIn) {
        hw.clear();
        double x;
        while (hwIn >> x) {
            hw.push_back(x);
        }
        hwIn.clear();
    }
    return hwIn;
}

istream &read_inf(istream &infoIn, student_info &oneStudent) {
    infoIn >> oneStudent.name >> oneStudent.midterm >> oneStudent.final;
    read_hw(infoIn, oneStudent.homework);
    return infoIn;
}

bool compare(const student_info &s1, const student_info &s2) {
    return s1.name < s2.name;
}