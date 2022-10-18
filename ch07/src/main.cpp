//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

int main(int argc, char **argv) {
    //
    cout << "-----------------------use genetic func to add string-------------------" << endl;
    vector<int> u(10, 100);
    vector<int> v(19, 10);
    copy(u.begin(), u.end(), v.begin());
    for (auto x: v) cout << x << " ";

    vector<string> s{"abc", "def", "=ghi", "--ti"};
    cout << endl;
//    string t = accumulate(s.begin(), s.end(),string(""));
    string t = accumulate(s.begin(), s.end(), string()); // cannot just use "" !!!!
    cout << t << "\n" << endl;

    cout << "-----------------------count string num-------------------" << endl;
    unordered_map<string, int> count_string;
    vector<string> bubble{"woman", "woman", "woman", "woman", "can", "can", "code", "code", "code"};
    for (string &str: bubble) count_string[str]++;
    for (auto &item: count_string) cout << item.first << ": " << item.second << endl;
    cout << "\n" << endl;
    return 0;
}