//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "student_info.hpp"
#include "grade.hpp"

using namespace std;

int main(int argc, char **argv) {
    Student_info one;
    vector<Student_info> all;
    string::size_type maxL = 0;
    while(read(cin, one)){
        all.push_back(one);
        maxL = max(maxL, one.name.size());
    }
    sort(all.begin(), all.end(), compare);
    for (auto a : all){
        cout << a.name << string(maxL + 2 - a.name.size(), ' ');
        try {
            double val = grade(a);
            cout << val << endl;
        }
        catch (domain_error e){
            cout << e.what();
        }
    }
    return 0;
}