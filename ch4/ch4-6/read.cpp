#include <iostream>
#include <vector>
#include "student_info.h"
#include "read.h"
#include "grade.h"
using std::vector;
using std::istream;


istream& read_hw(istream& in, vector<double>& hw){
    if(in){
        hw.clear();
        double x;
        while (in >> x)
        {
            hw.push_back(x);
        } 
        in.clear();
    }
    return in;
}

istream& read(istream& is, Student_info& s){
    double midterm, final;
    vector<double> homework;
    is >> s.name >> midterm >> final;
    read_hw(is, homework);
    // std::cout << (bool)is;
    if(is)
        s.grade = grade(midterm, final, homework);
        // std::cout << "time" << std::endl;
    return is;
}
