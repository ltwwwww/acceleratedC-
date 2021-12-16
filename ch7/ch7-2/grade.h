#ifndef GUARD_GRADE_H
#define GUARD_GRADE_H
#include <vector>
#include "student_info.h"

double median(std::vector<double>);

double grade(double, double, double);

double grade(double, double, const std::vector<double>&);

double grade(const Student_info&);


#endif