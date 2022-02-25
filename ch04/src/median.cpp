//
// Created by dora on 22/2/2022.
//
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

double median(vector<double> hw) {
    vector<double>::size_type len = hw.size();
    if (len == 0) throw domain_error("No Homework Grades");
    sort(hw.begin(), hw.end());
    vector<double>::size_type mid = len / 2;
    return len % 2 == 1 ? hw[mid] : (hw[mid] + hw[mid - 1]) / 2;
}
