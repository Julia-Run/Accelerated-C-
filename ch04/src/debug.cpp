//
// Created by dora on 23/2/2022.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;
struct student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

istream &read_hw(istream &hwIn, vector<double> &hw) {
    double y = 0.0;
    hwIn >> y;
//    if (hwIn) {
//        hw.clear();
        double x;
        while (hwIn >> x) {
            hw.push_back(x);
        }
//        hwIn.clear();
//    }
    return hwIn;
}

int main() {
    vector<double> hw;
    read_hw(cin, hw);
    for (auto &i: hw) {
        cout << i << "  ";
    }
}