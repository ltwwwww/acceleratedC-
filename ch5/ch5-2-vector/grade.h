#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info&);
bool pgrade(const Student_info&);
std::vector<Student_info> extrace_fails1(std::vector<Student_info>&);
std::vector<Student_info> extrace_fails2(std::vector<Student_info>&);
std::vector<Student_info> extrace_fails3(std::vector<Student_info>&);
#endif