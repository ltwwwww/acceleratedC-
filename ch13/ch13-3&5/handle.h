#pragma once
#include <iostream>
#include "student_info.h"
#include <stdexcept>
#include <string>
class Student_info{
public:
    Student_info() : cp(0){};
    Student_info(std::istream& is) : cp(0) { read(is); };
    Student_info(const Student_info&);
    Student_info& operator=(const Student_info&);
    ~Student_info(){ delete cp; }

    std::istream& read(std::istream&);

    std::string name() const {
        if(cp) return cp->name();
        else throw std::runtime_error("uninitilized student");
    }
    double grade() const {
        if(cp) return cp->grade();
        else throw std::runtime_error("uninitilized student");
    }

    bool valid() const { return cp->valid(); }

    std::string grade_str() const;
    static bool compare(const Student_info& a, const Student_info& b){
        return a.name() < b.name();
    }

private:
    Core* cp;
};