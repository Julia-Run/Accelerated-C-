//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include "vec.hpp"
#include "Str.hpp"

using namespace std;

int main(int argc, char **argv) {
    vec<int> v0(3, 15);
    vec<int> v(v0.begin(), v0.end());
    std::cout << v.size() << std::endl;
    for (auto i: v) std::cout << i << " ";
    std::cout << std::endl;
    v.push_back(16);
    v.push_back(17);
    v[0] = 10;
    v[1] = 12;
    std::cout << v.size() << std::endl;
    for (auto it = v.begin(); it != v.end(); it++) std::cout << *it << " ";
    std::cout << std::endl;

    Str s1 = "hello";
//    Str s2 = "world";
    Str s2;
    cin >> s2;
//    Str s = s1 + ", " + s2 + "! ";
    Str s = s1 + ", ";  // add 3 terms will cause error here
    s += s2;
    cout << s2.size() << "  " << s2 << endl;
    cout << s.size() << "  " << s << endl;
    return 0;
}