#include <stdexcept>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include "median.h"

using std::domain_error;
using std::vector;

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

vector<Student_info> extrace_fails(vector<Student_info>& s){
    vector<Student_info> fail;

    vector<Student_info>::size_type i = 0;
    vector<Student_info>::size_type ori_size = s.size();
    while(i != s.size()){
        if(fgrade(s[i])){
            fail.push_back(s[i]);
            
        }else{
            s.insert(s.begin(), s[i]);
            ++i;
        }
        ++i;
    }
    s.resize(ori_size - fail.size());
    return fail;
}