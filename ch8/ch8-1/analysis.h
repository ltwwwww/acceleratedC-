#pragma once
#include <iostream>
#include <vector>
#include "median.h"
#include "student_info.h"
#include <string>

void write_analysis(std::ostream& , const std::string& , 
                    double analysis(const Student_info&),
                    const std::vector<Student_info>& ,
                    const std::vector<Student_info>& );

double median_analysis(const std::vector<Student_info>&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);
double grade_analysis(const std::vector<Student_info>&, double grade(const Student_info&));



template <typename Function>
double template_analysis(const std::vector<Student_info>& students, Function func){
    std::vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), func);
    return median(grades);
}