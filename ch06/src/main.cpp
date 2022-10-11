//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef string::const_iterator iter;


bool space(char c) {
    return c == ' ';
}

bool not_space(char c) {
    return !space(c);
}

vector<string> split_s(const string &s) {
    vector<string> res;
    auto i = s.begin();
    while (i != s.end()) {
        i = find_if(i, s.end(), not_space);
        auto j = find_if(i, s.end(), space);
        if (i != s.end()) res.push_back(string(i, j));
        i = j;
    }
    return res;
}

vector<string> split_s_ch05(const string &s) {
    vector<string> res;
    int i = 0;
    while (i != s.size()) {
        while (i < s.size() && space(s[i])) ++i;
        int j = i;
        while (j < s.size() && not_space(s[j])) ++j;
        if (i < s.size()) res.push_back(s.substr(i, j - i));
        i = j;
    }
    return res;
}

bool is_palindrome(const string &s) {
    return equal(s.begin(), s.end(), s.rbegin());
}


// ---------------- To find url  -------
// http://djfdkfgjsk --> :// --> find h --> find k --> done;


bool not_url_char(char c) {
    static const string url_all = "~;/?:&=@$-_.+!*'(),";
    return !(find(url_all.begin(), url_all.end(), c) != url_all.end() || isalnum(c));
}

iter url_end(iter b, iter e) {
    return find_if(b, e, not_url_char);
}

iter url_begin(iter b, iter e) {
    static const string s = "://";
    iter i = b;
    while ((i = search(b, e, s.begin(), s.end())) != e) {
        iter st = i;
        if (st != b && st + s.size() != e) { // boundaries
            while (st != b && !not_url_char(st[-1])) --st; // st settled;
            if (st != i && !not_url_char(i[s.size()])) return st;  // make sure end exist; then return
        }
        i += s.size();
    }
    return e;
}


vector<string> find_url(const string &s) {
    vector<string> res;
    iter b = s.begin(), e = s.end();
    while (b != e) {
        b = url_begin(b, e);  // here we make sure there must be an url;
        if (b != e) {
            iter e1 = url_end(b, e); // thus here e1 must exit;
            res.push_back(string(b, e1));
            b = e1;
        }
    }
    return res;
}


int main(int argc, char **argv) {

    vector<string> s{"this", "is", "chapter", "six"};
    vector<string> t{"I", "am", "for", "generic", "algorithm"};

    cout << "---------------- this is initial t --------------------------" << endl;
    for (auto it = t.begin(); it != t.end(); ++it) cout << *it << " ";
    cout << endl;

    copy(s.begin(), s.end(), back_inserter(t));
//    copy(s.begin(), s.end(), t.begin());  // cover. cannot change length
    cout << "---------------- this is t after using copy --------------------------" << endl;
    for (auto it = t.begin(); it != t.end(); ++it) cout << *it << " ";
    cout << endl;

    t.insert(t.end(), s.begin(), s.begin() + 2);
    cout << "---------------- this is t after using t.insert() --------------------------" << endl;
    for (auto it = t.begin(); it != t.end(); ++it) cout << *it << " ";
    cout << endl;

    string s1 = "    this    is     a     test    for find_if    ";
    cout << "---------------- this is t after using find_if --------------------------" << endl;
    auto c = split_s(s1);
    for (auto x: c) cout << x << " ";
    cout << endl;
    cout << "---------------- this is t after using dual pointers --------------------------" << endl;
    auto c1 = split_s_ch05(s1);
    for (auto x: c1) cout << x << " ";
    cout << endl;

    cout << endl;
    cout << "---------------- this is for using equal ---------------------------------------------" << endl;
    string se = "1234567890987654321";
    if (is_palindrome(se)) cout << se << " is palindrome." << endl;
    else cout << "NO" << endl;

    cout << "\n\n\n\n" << endl;
    cout << "---------------- To find url  --------------------------" << endl;
    string url = "  fegfh http://ffgsrgsrb/?#  $ http://cuhk.edu  http://test#34252/ ";
    vector<string> urls = find_url(url);
    for (auto x: urls) cout << x << "     ";
    cout << endl;
    return 0;
}