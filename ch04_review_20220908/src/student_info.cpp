//
// Created by dora on 8/9/2022.
//

#include <iostream>
#include <vector>
#include "student_info.hpp"

using namespace std;

bool compare(const Student_info &a, const Student_info &b) {
    return a.name < b.name;
}

istream &read_hw(istream &is, vector<double> &hw){
    if (is){
        hw.clear();
        double x;
        while(is >> x) hw.push_back(x);
        is.clear();
    }
    return is;
}


istream &read(istream &is, Student_info &a) {
    is >> a.name >> a.midterm >> a.final;
    read_hw(is, a.hw);
    return is;
}

