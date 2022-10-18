//
// Created by dora on 10/9/2022.
//
#include "funcs.hpp"
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

void useIter(vector<int> &a, int x) {
    vector<int> b(a);

    cout << "using index: " << endl;
    int i = 0;
    while (i != a.size()) {
        if (a[i] == x) a.erase(a.begin() + i);
        else ++i;
    }
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " ";
    cout << endl;


    cout << "using iterator: " << endl;
    vector<int>::iterator it = b.begin();
    while (it != b.end()) {
        if (*it == x) it = b.erase(it);
        else it++;
    }
    for (auto j = b.begin(); j != b.end(); ++j) cout << *j << " ";
    cout << endl;

    if (a==b) cout << "------------- Great Job! -------------\n" << endl;
}

void testList(list<int> &a, int x){
    cout << "test list: " << endl;
    list<int>::iterator it = a.begin();
    while(it!=a.end()){
        if (*it == x) it = a.erase(it);
        else it++;
    }
    for (auto i = a.begin(); i!=a.end(); ++i) cout <<  *i << " ";
    cout << "\n" << endl;
}

vector<string> split_str(const string &s){
    vector<string> res;
    int i = 0;
    while(i!=s.size()){
        while(i!=s.size() && isspace(s[i])) i++;
        int j = i;
        while(j!=s.size() && !isspace(s[j])) j++;
        if (i!=j){
            string temp = s.substr(i, j-i);
            res.push_back(temp);
        }
        i = j;
    }
    return res;
}

vector<string> frame(const vector<string> &s){
    vector<string>::size_type maxLen = 0;
    for (const auto & it : s){
        maxLen = max(maxLen, it.size());
    }

    int w = maxLen + 4;
    string border(w, '*');

    vector<string> res;
    res.push_back(border);

    for (vector<string>::const_iterator it = s.begin(); it!=s.end(); ++it){
        string t = "* " + *it + string(w-2- it->size()-1, ' ') + '*';
        res.push_back(t);
    }
    res.push_back(border);
    res.insert(res.begin(), res.begin(), res.end());
    return res;
}
