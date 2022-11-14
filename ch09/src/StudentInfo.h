//
// Created by dora on 11/14/22.
//

#ifndef CPP_TEMPLATE_STUDENTINFO_H
#define CPP_TEMPLATE_STUDENTINFO_H

class StudentInfo{

private:
    double mid, final;
    std::string name;
    std::vector<double> homework;

public:
    std::string getName() const {return name;}
    bool valid() const {return homework.empty(); }
    double grade() const;
    StudentInfo();
    StudentInfo(std::string, std::vector<double>);
};

bool compare(StudentInfo &, StudentInfo &);

#endif //CPP_TEMPLATE_STUDENTINFO_H
