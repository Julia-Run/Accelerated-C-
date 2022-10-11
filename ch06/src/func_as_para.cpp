//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct StudentInfo {
    string name;
    double mid, final;
    vector<double> hw;
};

double medium(vector<double> &g) {
    sort(g.begin(), g.end());
    int n = g.size(), m = n / 2;
    return n % 2 == 1 ? g[m] : (g[m] + g[m - 1]) / 2;
}

double avg(const vector<double> &g) {
    double sum = accumulate(g.begin(), g.end(), 0.0);
    return sum / g.size();
}

double grade(double m, double f, double h) {
    return m * 0.2 + f * 0.3 + h * 0.5;
}

double grade(const StudentInfo &s) {
    if (s.hw.empty()) throw domain_error("No Homework Grades!");
    double h = accumulate(s.hw.begin(), s.hw.end(), 0.0) / s.hw.size();
    return s.mid * 0.2 + s.final * 0.3 + h * 0.5;
}

double grade_aux(const StudentInfo &s) {
    try {
        return grade(s);
    }
    catch (domain_error) {
        return grade(s.mid, s.final, 0);
    }
}

vector<double> analysis(const vector<StudentInfo> &group, double grade_aux(const StudentInfo &)) {
    vector<double> grades;
    transform(group.begin(), group.end(), back_inserter(grades), grade_aux);
    return grades;
}

bool pass_(StudentInfo &s) {
    if (grade_aux(s) > 60) return true;
    return false;  // this has to be written, or fail will never return true;
}

bool fail(StudentInfo &s) {
    return !pass_(s);
}


int main(int argc, char **argv) {
    vector<StudentInfo> s{{"Tom",  100, 93, {100, 60}},
                          {"John", 90,  90},
                          {"John Little", 100,  300, {30, 50, 0}},
    };
    vector<StudentInfo> fails;
    remove_copy_if(s.begin(), s.end(), back_inserter(fails), pass_);
    vector<StudentInfo> pass(s);
    pass.erase(remove_if(pass.begin(), pass.end(), fail), pass.end());
    auto g = analysis(s, grade_aux);
    cout << "Medium grade is " << medium(g) << endl;
    cout << pass.size() << " passed, " << fails.size() << " failed" << endl;
    auto it = stable_partition(s.begin(), s.end(), pass_);  // keep ordered in one group
    vector<StudentInfo> fails1(it, s.end());
    s.erase(it, s.end());
    cout << s.size() << " passed, " << fails1.size() << " failed" << endl;
    return 0;
}