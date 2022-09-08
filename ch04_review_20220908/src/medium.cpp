//
// Created by dora on 8/9/2022.
//
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "medium.hpp"

using namespace std;

double medium(vector<double> hw) {
    if (hw.empty()) throw domain_error("NO homework grades");
    sort(hw.begin(), hw.end());
    vector<double>::size_type mid = hw.size() / 2;
    return (hw.size() % 2 == 0) ? (hw[mid] + hw[mid - 1]) / 2 : hw[mid];
}