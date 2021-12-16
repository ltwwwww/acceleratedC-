#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iterator>
#include "grade.h"
#include "Student_info.h"
#include "median.h"

using std::stable_partition;
using std::domain_error;
using std::vector;
using std::back_inserter;
using std::remove_copy_if;
using std::remove_if;

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

bool fgrade(const Student_info& s){
    return grade(s) < 60;
}

bool pgrade(const Student_info& s){
    return !fgrade(s);
}

vector<Student_info> extrace_fails1(vector<Student_info>& s){
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

vector<Student_info> extrace_fails2(vector<Student_info>& s){
    vector<Student_info> fail;
    remove_copy_if(s.begin(), s.end(), back_inserter(fail), pgrade);
    s.erase(remove_if(s.begin(), s.end(), fgrade), s.end());
    return fail;
}

vector<Student_info> extrace_fails3(vector<Student_info>& s){
    vector<Student_info>::iterator iter = 
        stable_partition(s.begin(), s.end(), pgrade);
    vector<Student_info> fail(iter, s.end());
    s.erase(iter, s.end());
    return fail;
}