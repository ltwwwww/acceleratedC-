#pragma once
#include <iostream>
#include "student_info.h"
#include <stdexcept>
#include <string>
#include "reference-handle.h"

class Student_info{
public:
    Student_info() : hp(0){};
    Student_info(std::istream& is) : hp(0) { read(is); };

    std::istream& read(std::istream&);

    std::string name() const {
        if(hp) return hp->name();
        else throw std::runtime_error("uninitilized student");
    }
    double grade() const {
        if(hp) return hp->grade();
        else throw std::runtime_error("uninitilized student");
    }

    static bool compare(const Student_info& a, const Student_info& b){
        return a.name() < b.name();
    }
private:
    Ref_handle<Core> hp;
};