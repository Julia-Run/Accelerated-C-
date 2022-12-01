//
// Created by dora on 11/30/22.
//

#ifndef CPP_TEMPLATE_CORE_HPP
#define CPP_TEMPLATE_CORE_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <numeric>

class Core {
    friend class Student;
private:
    std::string name_n;
protected:
    double mid, final;
    std::vector<double> hw;
    void load_name(std::string &s) {name_n = s; }

    std::istream &read_pub(std::istream &is) {
        is >> name_n >> mid >> final;
        return is;
    }

    void read_hw(std::istream &is) {
        hw.clear();
        double x;
        while (is >> x) hw.push_back(x);
    }

    double grade_hw() {
        if (hw.empty()) return 0;
        double sum = std::accumulate(hw.begin(), hw.end(), 0.0);
        return sum / hw.size();
    }

    virtual Core* clone() { return new Core(*this); }

    std::vector<std::string> str_to_vec(const std::string &s){
        std::vector<std::string> a;
        for (int i = 0; i<s.size(); ++i){
            while(std::isspace(s[i])) i++;
            if (i!=s.size()) {
                int j = i;
                while (j < s.size() && !std::isspace(s[j])) j++;
                a.emplace_back(s.begin() + i, s.begin() + j);
                i = j;
            }
        }
        return a;
    }

    std::vector<double> vec_str2double (std::vector<std::string> & a){
        std::vector<double> num;
        for (int i = 2; i<a.size(); ++i){
            std::string cur = a[i];
            double res = 0;
            for (int j = 0; j<cur.size(); ++j) res = res*10+(cur[j]-'0');
            num.push_back(res);
        }
        return num;
    }

public:
    Core() : mid(0), final(0) {}

    Core(std::istream &is) { read(is); }

    std::string name() {return name_n; }

    virtual ~Core() { }

    virtual std::istream &read(std::istream &is) {
        read_pub(is);
        read_hw(is);
        is.clear();
        return is;
    }

    virtual void read(std::string & s){
        auto a = str_to_vec(s);
        auto g = vec_str2double(a);
        mid = g[0];
        final = g[1];
        name_n = a[1];
        hw.clear();
        for (int i = 2; i<g.size(); ++i) hw.push_back(g[i]);
    }

    virtual double grade() { return mid * 0.3 + final * 0.3 + grade_hw() * 0.4; }
};

#endif //CPP_TEMPLATE_CORE_HPP
