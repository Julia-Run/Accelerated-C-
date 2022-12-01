//
// Created by FORREST1901 on 9/16/20.
//

#include <iostream>
#include "Core.hpp"
#include "Grad.hpp"
#include "Student.hpp"
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;


string readfile(string &filename, string &temp) {
    ifstream infile(filename);
    if (getline(infile, temp)) //test the read for success
    {
        return temp;
    } else {
        cout << "failed to read file " << filename << endl;
    }
}

int main(int argc, char **argv) {
    vector<Student> all;
    Student s;

    string::size_type maxlen = 0;
//    while(s.read(cin)){
//        maxlen = max(maxlen, s.name().size());
//        all.push_back(s);
//        cout << s.name() << ": " << s.grade() << endl;
//    }
    string fileName = "/home/dora/Codes/Accelerated-Cpp/ch13/src/s1.txt";  // here has to be full path;
    ifstream inFile(fileName);
    std::string t;
//    if (!inFile.good()) {
//        cout << "Unable to open the file named " << fileName;
//        exit (1);
//    }
    cout << "Original Data: " << endl;
    while (true) {
        getline(inFile, t);
        cout << "    " << t << "   ";
        s.read(t);
        maxlen = max(maxlen, s.name().size());
        all.push_back(s);
        cout << s.name() << ": " << s.grade() << endl;
        if (inFile.eof()) {
            break;
        }
    }

    sort(all.begin(), all.end(), Student::compare);

    cout << "\nFinal grades (sorted by name): " << endl;
    for (auto member: all) {
        cout << "    " << member.name() << ": " << member.grade() << endl;
    }

    return 0;
}