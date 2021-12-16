#ifndef GUARD_READ_H
#define GUARD_READ_H
#include <iostream>
#include <vector>
#include "student_info.h"
#include "read.h"

std::istream& read_hw(std::istream&, std::vector<double>&);

std::istream& read(std::istream&, Student_info&);

#endif

