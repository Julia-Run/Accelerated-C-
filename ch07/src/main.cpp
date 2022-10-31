//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

vector<string> split(const string &s) {
    vector<string> c;
    auto i = s.begin();
    while (i != s.end()) {
        while (isspace(*i)) i++;
        // i != space;
        auto j = i;
        while (isalnum(*j) || *j == '<' || *j == '>' || *j == '-') j++;
        // j = space;
        if (i != s.end()) c.emplace_back(i, j);
        i = j;
    }
    return c;
}

unordered_map<string, int> countWords(const vector<string> &a) {
    unordered_map<string, int> m;
    for (const string &s: a) m[s]++;
    return m;
}

unordered_map<string, vector<int> > makeTable(istream &in, vector<string> find_words(const string &) = split) {
    string times;
    getline(in, times);
    int len = times.size(), res = 0;
    for (int i = 0; i < len; i++) res = res * 10 + (times[i] - '0');

    cout << "\nplease type in: " << endl;
    unordered_map<string, vector<int>> c;
    int num = 0;
    string curr;
    while (num < res) {
        getline(in, curr);
        num++;
        if (num == 0) continue;
        vector<string> line = find_words(curr);
        for (auto const &word: line) c[word].push_back(num);
    }
    return c;
}

typedef vector<string> Rule;
typedef vector<Rule> RuleCollection;
typedef unordered_map<string, RuleCollection> Grammar;


Grammar constructGrammar() {
    ifstream inFile;
    inFile.open("/home/dora/Codes/Accelerated-Cpp/ch07/src/grammar.txt");  // "grammar.txt" cannot open
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    Grammar res;
    string curr;
    while (getline(inFile, curr)) {
        vector<string> line = split(curr);
        res[line[0]].push_back(Rule(line.begin() + 1, line.end()));
    }
    inFile.close();
//    for (auto c : res){
//        cout << c.first << " ------ " << endl;
//        for (auto x : c.second) {
//            for (auto y : x) cout << y << " ";
//            cout << endl;
//        }
//    }
    return res;
}

int nrand(int n) {
    int lim = 40;  // RAND_MAX
    if (n < 0 || n > lim) throw domain_error("Out-of-Range");
    int bucketSize = lim / n;
    int r;
    do r = rand() / bucketSize;
    while (r >= n);
    return r;
}

bool isType(const string &s){
    return s[0] == '<' && s[s.size() - 1] == '>';
}


void gen_aux(const Grammar &g, const string &s, vector<string> &res) {   // Attention here:  & res
    if (!isType(s)) res.push_back(s);
    else {
//        cout << "t" << endl;
        auto it = g.find(s);   // pointer to a pair;
        if (it == g.end()) throw domain_error("Empty Rule");
        RuleCollection rules = it->second;  // all possibilities
        int x = nrand(rules.size()); // rand one in it's range;
        Rule rx = rules[x];
        for (const auto& ele : rx) {
            gen_aux(g, ele, res);
//            cout << ele << endl;
//            cout << isType(ele) << endl;
        }
    }
}

vector<string> genSentence(const Grammar &g) {
    vector<string> res;
    gen_aux(g, "<sentence>", res);
    return res;
}


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
    vector<string> bubble{"woman", "woman", "woman", "woman", "can", "can", "code", "code", "code"};
    auto c = countWords(bubble);
    for (auto &item: c) cout << item.first << ": " << item.second << endl;
    cout << "\n" << endl;

    cout << "-----------------------construct a table-------------------" << endl;
    cout << "How many lines input will you do? \n";
    auto table = makeTable(cin);
    for (auto it = table.begin(); it != table.end(); ++it) {
        cout << it->first << " in following line(s): ";
        vector<int> lines = it->second;
        auto st = lines.begin();
        cout << *st;
        st++;
        while (st != lines.end()) cout << ", " << *st, st++;
        cout << "\n";
    }
    cout << "\n" << endl;

    cout << "-----------------------construct a sentence-------------------" << endl;
    auto res = genSentence(constructGrammar());
//    cout << res.size() << endl;
    for (auto it : res) cout << it << " ";
    cout << endl;
    return 0;
}