#include <string>
#include "letter_grade.h"

std::string letter_grade(double x){
    static const double num[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };
    static const char* const grade[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };
    static const size_t length = sizeof(num) / sizeof(*num);
    for(size_t i = 0; i < length; ++i){
        if(x >= num[i]) return grade[i];
    }
    
    return "\?\?\?";
}