//
// Created by dora on 22/2/2022.
//

#ifndef CPP_TEMPLATE_STUDENT__INFO_H
#define CPP_TEMPLATE_STUDENT__INFO_H

#include <string>
#include <vector>
#include <iostream>
struct student_info
{
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

std::istream& read_hw(std::istream&, std::vector<double>& );
std::istream& read_inf(std::istream& , student_info&);
bool compare(const student_info& , const student_info& );

#endif //CPP_TEMPLATE_STUDENT__INFO_H
