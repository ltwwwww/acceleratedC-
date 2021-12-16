#pragma once 
#include "Ptr.h"
#include "pic_base.h"
#include <vector>
#include <string>
#include <iostream>
class Picture {
friend std::ostream& operator<<(std::ostream& , const Picture&);
friend Picture frame(const Picture&);
friend Picture hcat(const Picture&, const Picture&);
friend Picture vact(const Picture&, const Picture&);
public:
    Picture(){}
    Picture(const std::vector<std::string>& = std::vector<std::string>());
    Picture(Pic_base* rhs) : p(rhs){}


private:
    Ptr<Pic_base> p;
};

Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vact(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);