//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include "vec.h"

using namespace std;

int main(int argc, char **argv) {
    vec<int> v0(3, 15);
    vec<int> v(v0.begin(), v0.end());
    std::cout << v.size() << std::endl;
    for (auto i: v) std::cout << i << " ";
    std::cout << std::endl;
    v.pushBack(16);
    v.pushBack(17);
    v[0] = 10;
    v[1] = 12;
    std::cout << v.size() << std::endl;
    for (auto it = v.begin(); it!=v.end(); it++) std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}