//
// Created by dora on 12/2/22.
//

#ifndef CPP_TEMPLATE_CORE_HPP
#define CPP_TEMPLATE_CORE_HPP

#include <string>
#include <vector>
#include <numeric>

class Core {
protected:
    std::string name;
    double mid, final;
    std::vector<double> hw;

    double get(const std::string &s) {
        double res = 0;
        for (char i: s) res = res * 10 + (i - '0');
        return res;
    }

    std::pair<std::vector<std::string>, std::vector<double>> str2vec(const std::string &s) {
        std::vector<std::string> all;
        std::vector<std::string> str;
        std::vector<double> num;
        const int n = (int) s.size();
        for (int i = 0; i < n; ++i) {
            while (std::isspace(s[i])) i++;
            if (i != n) {
                int j = i;
                while (j != n && !isspace(s[j])) j++;
                if (j != i) all.emplace_back(s.begin() + i, s.begin() + j);
                i = j;
            }
        }

        for (int i = 0; i < all.size(); ++i) {
            if (i <= 1) str.emplace_back(all[i]);
            else num.emplace_back(get(all[i]));
        }
        std::pair<std::vector<std::string>, std::vector<double>> ans{str, num};
        return ans;
    }

    double cal_hw() {
        if (hw.empty()) return 0;
        double sum = std::accumulate(hw.begin(), hw.end(), 0.0);
        return sum / (int) hw.size();
    }

public:
    Core() : mid(0), final(0) {}

    Core(const std::string &s) : mid(0), final(0) { read(s); }

    virtual ~Core() {};

    virtual double grade() {
        return mid + 0.3 + final * 0.3 + cal_hw() * 0.4;
    }

    std::string getName(){
        return name;
    }

    virtual void read(const std::string &s) {
        auto [str, num] = str2vec(s);
        name = str[1];
        mid = num[0];
        final = num[1];
        hw.clear();
        hw = std::vector<double>(num.begin() + 2, num.end());
    }

    virtual Core* clone() {return  new Core(*this); }
};

#endif //CPP_TEMPLATE_CORE_HPP
