#include <iostream>
#include <string>
#include <vector>
#include "student_info.h"
#include "grade.h"

using std::string;
using std::vector;
// using std::string;
using std::istream;


Student_info::Student_info() : midterm(0), final(0){}

Student_info::Student_info(std::istream& is) { read(is); }

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}

istream& read_hw(istream& is, vector<double>& hw){
    if(is){
        hw.clear();
        double x;
        while(is >> x){
            hw.push_back(x);
        }
        is.clear();
    }
    return is;
}

istream& Student_info::read(istream& is){
    is >> n >> midterm >> final;
    read_hw(is, homework);
    return is;
}


bool compare(const Student_info& a, const Student_info& b){
    return a.name() < b.name();
}