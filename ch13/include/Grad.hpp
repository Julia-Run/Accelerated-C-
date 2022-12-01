//
// Created by dora on 11/30/22.
//

#ifndef CPP_TEMPLATE_GRAD_HPP
#define CPP_TEMPLATE_GRAD_HPP

#include "Core.hpp"
#include <algorithm>

class Grad: public Core{
private:
    double thesis;
public:
    Grad():thesis(0){}
    Grad(std::istream& is) { read(is); }

    double grade(){
        return std::max(thesis, Core::grade());
    }

    std::istream& read(std::istream &is){
        read_pub(is);
        is >> thesis;
        read_hw(is);
        is.clear();
        return is;
    }

    Grad* clone() { return new Grad(*this); }

    void read(std::string & s){
        auto a = str_to_vec(s);
        auto g = vec_str2double(a);
        mid = g[0];
        final = g[1];
        thesis = g[2];
        load_name(a[1]);
        for (int i = 3; i<g.size(); ++i) hw.push_back(g[i]);
    }

};

#endif //CPP_TEMPLATE_GRAD_HPP
