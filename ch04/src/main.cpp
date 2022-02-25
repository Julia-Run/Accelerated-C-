//
// Created by FORREST1901 on 9/16/20.
//

#include "student _info.h"
#include "grade.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    student_info oneStudent;
    vector<student_info> students;
    string::size_type maxlength = 0; //longest name size;
    while (read_inf(cin, oneStudent)) {
        maxlength = max(maxlength, oneStudent.name.size());
        students.push_back(oneStudent);
    }
    sort(students.begin(), students.end(), compare);  //students sort by name;
    cout << "Please input:" << endl;
    // we can start output
    for (auto & student : students) {
        //for (vector<student_info>::size_type i = 0; i != students.size(); i++) {
        cout << student.name << string(maxlength + 2 - student.name.size(), ' ');
        try {
            double final_grade = grade(student);
            streamsize pre = cout.precision(); //current precision
            cout << setprecision(4) << final_grade << setprecision(pre);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}