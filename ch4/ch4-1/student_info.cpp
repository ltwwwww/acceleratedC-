#include "student_info.h"

bool compare(const Student_info& x, const Student_info& y){
    return x.name < y.name;
}