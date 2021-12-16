#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "student_info.h"
using namespace std;

Student_info::Student_info() : midterm(0) , final(0){};
Student_info::Student_info(std::istream& is) { read(is); };

double Student_info::grade() const{
    return (midterm + final) / 2.0;
}


istream& Student_info::read(istream& cin){
    cin >> n >> midterm >> final;
    read_hw(cin, homework);
    if(grade() >= 60){
        score = "pass";
    }else{
        score = "fail";
    }
    
    return cin;
}

double grade(double mid, double fin, std::vector<double> homework){
    return 0.2 * mid + 0.4 * fin + 0.4 * median(homework);
}

double median(vector<double> vec){
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if(size == 0){
        throw domain_error("median of an empty vector!");
    }
    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

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

bool compare(const Student_info& a, const Student_info& b){
    return a.name() < b.name();
}