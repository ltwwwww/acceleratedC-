#include <stdexcept>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include "grade.h"
#include "Student_info.h"
#include "median.h"

using std::domain_error;
using std::vector;
using std::accumulate;
using std::remove_copy;
using std::back_inserter;

double grade(double midterm, double final, double homework){
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw){
    if (hw.size() == 0){
        throw domain_error("Students has done no homework");
    }
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s){
    return grade(s.midterm, s.final, s.homework);
}

double aux_grade(const Student_info& s){
    try{
        return grade(s);
    }catch(domain_error){
        return grade(s.midterm, s.final, 0);
    }   
}

double average(const vector<double>& hw){
    return accumulate(hw.begin(), hw.end(), 0.0) / hw.size();
}

double average_grade(const Student_info& s){
    return grade(s.midterm, s.final, average(s.homework));
}

double optimistic_median(const Student_info& s){
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
    if(nonzero.empty()){
        return grade(s.midterm, s.final, 0);
    }else{
        return grade(s.midterm, s.final, median(nonzero));
    }
}

bool fgrade(const Student_info& s){
    return grade(s) < 60;
}

vector<Student_info> extrace_fails(vector<Student_info>& s){
    vector<Student_info> fail;

    vector<Student_info>::iterator iter = s.begin();
    while(iter != s.end()){
        if(fgrade(*iter)){
            fail.push_back(*iter);
            iter = s.erase(iter);
        }
        else
            iter++;
    }
    return fail;
}