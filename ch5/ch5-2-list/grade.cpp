#include <stdexcept>
#include <vector>
#include <list>
#include "grade.h"
#include "Student_info.h"
#include "median.h"

using std::domain_error;
using std::vector;
using std::list;

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

list<Student_info> extrace_fails(list<Student_info>& s){
    list<Student_info> fail;

    list<Student_info>::iterator iter = s.begin();
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