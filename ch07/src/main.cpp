//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char **argv) {

    vector<int> u(10, 100);
    vector<int> v(19,10);
    copy(u.begin(), u.end(), v.begin());
    for (auto x : v) cout << x << " ";

    vector<string> s{"abc", "def", "=ghi", "--ti"};
    cout << endl;
//    string t = accumulate(s.begin(), s.end(),string(""));
    string t = accumulate(s.begin(), s.end(),string()); // cannot just use "" !!!!
    cout << t << endl;
    return 0;
}