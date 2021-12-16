#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "student_info.h"
#include "grade.h"

using std::string;
using std::vector;
// using std::string;
using std::istream;
using std::min;
using std::max;
using std::cout;
using std::endl;


Core::Core() : midterm(0), final(0) { cout << "Core::Core() : midterm(0), final(0)" << endl; }

Core::Core(std::istream& is) { read(is); cout << "Core::Core(std::istream&)" << endl;}

istream& Core::read_common(istream& is){
    is >> n >> midterm >> final;
    return is;
}

istream& Core::read(istream& is){
    read_common(is);
    read_hw(is, homework);
    return is;
}

double Core::grade() const {
    std::cout<< "Core::grade" << std::endl;
    return ::grade(midterm, final, homework);
}

Grad::Grad() : Core(), thesis(0){ cout << "Grad::Grad() : Core(), thesis(0)" << endl; }
Grad::Grad(std::istream& is){ read(is); cout << "Grad::Grad(std::istream&)" << endl; }

double Grad::grade() const{
    std::cout<< "Grad::grad" << std::endl;
    return min(Core::grade(), thesis);
}


istream& Grad::read(istream& is){
    // is >> n >> midterm >> final;
    read_common(is);
    is >> thesis;
    read_hw(is, homework);
    return is;
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

bool compare(const Core& a, const Core& b){
    return a.name() < b.name();
}

bool compare_ptrs(const Core* a, const Core* b){
    return a->name() < b->name();
}