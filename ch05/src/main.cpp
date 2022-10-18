//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include <vector>
#include "funcs.hpp"

using namespace std;


int main(int argc, char **argv) {
    vector<int> a{1, 3, 4, 5, 7, 8, 6};
    useIter(a, 5);
    list<int> b{1, 3, 4, 5, 7, 8, 6};
    testList(b, 1);
    string s = "this is a test of the string split";
    cout << "Initial: " <<  s << endl;
    auto res = split_str(s);
    cout << "Result:  ";
    for (auto it : res) cout << it << " ";
    cout << "\n" << endl;
    auto res1 = frame(res);
    for (auto it : res1) cout << it << endl;
    cout << "\n" << endl;

    return 0;
}