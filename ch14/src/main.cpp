//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include "Student.hpp"
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
    vector<Student> all;
    Student s;

    string::size_type maxlen = 0;

    string fileName = "/home/dora/Codes/Accelerated-Cpp/ch14/src/s1.txt";  // here has to be full path;
    ifstream inFile(fileName);
    std::string t;

    cout << "Original Data: " << endl;
    while (true) {
        getline(inFile, t);
        cout << "    " << t << "   ";
        s.read(t);
        maxlen = max(maxlen, s.getName().size());
        all.push_back(s);
        cout << s.getName() << ": " << s.grade() << endl;
        if (inFile.eof()) {
            break;
        }
    }

    sort(all.begin(), all.end(), Student::compare);

    cout << "\nFinal grades (sorted by name): " << endl;
    for (auto member: all) {
        cout << "    " << member.getName() << ": " << member.grade() << endl;
    }

    return 0;
}
