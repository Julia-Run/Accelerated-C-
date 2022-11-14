//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include <vector>
#include "StudentInfo.h"
using namespace std;

int main(int argc, char **argv) {

    vector<double> s{100,100,60,60,60};
    StudentInfo s1 = StudentInfo("Allan", s);
    cout << s1.getName() << ": " << s1.grade() << endl;
    return 0;
}