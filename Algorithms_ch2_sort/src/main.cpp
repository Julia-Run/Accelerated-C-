//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void quickSort(vector<int> &nums, int lo, int hi) {
    if (lo >= hi - 1) return;  // one element return
    int v = nums[lo];
    int i = lo, j = hi;
    while (true) {
        while (nums[++i] < v) if (i >= hi - 1) break; //  if one element, nums[++i] overflow
        while (v < nums[--j]) {}
        if (i >= j) break;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    nums[lo] = nums[j];
    nums[j] = v;
    quickSort(nums, lo, j);
    quickSort(nums, j + 1, hi);
}


int main(int argc, char **argv) {
//    vector<int> a = {1, -1};
//    quickSort(a, 0, a.size());
//    for (auto x: a) cout << x << "   ";
//    cout << endl;
    vector<int> a = {1, 4, 1, 1, 1, 1, 3, 3, 3, 33, 3, 20, 3, 3, 3, 5, 5};
    map<int, int> m;
    for (int i: a) ++m[i];
    vector<vector<int>> v(8);
    for (auto x: m) { v[x.second].push_back(x.first); }
    cout << v.size() << endl;
    for (auto &x: v) {
        cout << x.size() << endl;
    }
    cout << endl;
    for (auto &x: v) {
        for (auto i: x) cout << i << "   ";
    }
}