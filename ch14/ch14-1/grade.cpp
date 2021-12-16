#include <vector>
#include <stdexcept>
#include "median.h"
#include "grade.h"

using std::vector;
using std::domain_error;

double grade(double mid, double final, double hw){
    return 0.2 * mid + 0.4 * final + 0.4 * hw;
}

double grade(double mid, double final, const vector<double>& hw){
    if(hw.size() == 0){
        throw domain_error("Student has done no homework");
    }
    return grade(mid, final, median(hw));
}