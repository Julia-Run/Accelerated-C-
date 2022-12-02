//
// Created by dora on 12/2/22.
//

#ifndef CPP_TEMPLATE_GRAD_HPP
#define CPP_TEMPLATE_GRAD_HPP

#include "Core.hpp"

class Grad: public Core{
private:
    double thesis;
public:
    Grad():thesis(0){}
    Grad(const std::string &s){read(s);}

    void read(const std::string &s){
        auto [names, scores] = str2vec(s);
        name = names[1];
        mid = scores[0];
        final = scores[1];
        thesis = scores[2];
        hw = std::vector<double> (scores.begin()+3, scores.end());
    }

    double grade(){
        return std::max(Core::grade(), thesis);
    }

    Grad* clone() {return  new Grad(*this); }
};

#endif //CPP_TEMPLATE_GRAD_HPP
