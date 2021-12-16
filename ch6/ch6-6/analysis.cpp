#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include "Student_info.h"
#include "analysis.h"
#include "grade.h"
#include "median.h"
using std::vector;
using std::transform;
using std::back_inserter;
using std::ostream;
using std::string;
using std::endl;

void write_analysis(ostream& out, const string& name, 
                    double analysis(const Student_info&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt){
        out << name << ": median(did) = " << grade_analysis(did, analysis)
                    << ": median(didnt) = " << grade_analysis(didnt, analysis) << endl;
    }

double grade_analysis(const vector<Student_info>& students, double grade(const Student_info&)){
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade);
    return median(grades);   
}


// double median_analysis(const vector<Student_info>& students){
//     vector<double> grades;
//     transform(students.begin(), students.end(), back_inserter(grades), aux_grade);
//     return median(grades);
// }


// double average_analysis(const std::vector<Student_info>& students){
//     vector<double> grades;
//     transform(students.begin(), students.end(), back_inserter(grades), average_grade);
//     return median(grades); 
// }

// double optimistic_median_analysis(const std::vector<Student_info>& students){
//     vector<double> grades;
//     transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
//     return median(grades); 
// }