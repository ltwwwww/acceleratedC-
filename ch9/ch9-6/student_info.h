#pragma once
#include <vector>
#include <string>
#include <iostream>

class Student_info{
public:
    Student_info();
    Student_info(std::istream&);
    std::string name() const { return n;}
    double grade() const;
    std::istream& read(std::istream&);
    // std::istream& read_hw(std::istream&, std::vector<double>);
    bool valid() const { return !homework.empty(); }
    std::string flag() const { return score; }

private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
    std::string score;
};
bool compare(const Student_info&, const Student_info&);
double grade(double, double, std::vector<double>);
double median(std::vector<double>);
std::istream& read_hw(std::istream&, std::vector<double>&);