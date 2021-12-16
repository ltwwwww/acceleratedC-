#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H
#include <string>
#include <vector>

struct Student_info
{
    std::string name;
    double grade;
};

bool compare(const Student_info&, const Student_info&);



#endif