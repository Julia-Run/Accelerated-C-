//
// Created by dora on 11/14/22.
//
#include <utility>
#include <vector>
#include <string>
#include "StudentInfo.h"

using namespace std;

double grade(double a, double b, double c){  // helper1
    return a*0.3+b*0.3+c*0.4;
}

double findAvg(const vector<double> &v){
    double sum = 0;
    for (auto x : v) sum+=x;
    return sum/v.size();
}

double StudentInfo::grade() const{ // const
    return :: grade(mid, final, findAvg(homework));
}

StudentInfo::StudentInfo():mid(0), final(0) {};

StudentInfo::StudentInfo(string n, vector<double> s){
    name = n;
    mid = s[0];
    final = s[1];
    homework = {s.begin()+2, s.end()};
}

