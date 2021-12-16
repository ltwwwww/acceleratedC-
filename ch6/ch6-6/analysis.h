#pragma once
#include <iostream>
#include <vector>
#include "student_info.h"
#include <string>

void write_analysis(std::ostream& , const std::string& , 
                    double analysis(const Student_info&),
                    const std::vector<Student_info>& ,
                    const std::vector<Student_info>& );

// double median_analysis(const std::vector<Student_info>&);
// double average_analysis(const std::vector<Student_info>&);
// double optimistic_median_analysis(const std::vector<Student_info>&);
double grade_analysis(const std::vector<Student_info>&, double grade(const Student_info&));
