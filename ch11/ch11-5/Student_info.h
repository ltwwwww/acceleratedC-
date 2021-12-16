#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>
#include <iostream>
struct Student_info
{
    std::string name;
    double midterm, final;
    std::vector<double> homework;

    Student_info(){ std::cout << "create" << std::endl; }
    Student_info(const Student_info& rhs){
        std::cout << "copy" << std::endl;
        name = rhs.name;
        midterm = rhs.midterm;
        final = rhs.final;
        homework = rhs.homework;
    }
    Student_info& operator=(const Student_info& rhs){
        std::cout << "assign" << std::endl;
        if(this != &rhs){
            name = rhs.name;
            midterm = rhs.midterm;
            final = rhs.final;
            homework = rhs.homework; 
        }
        return *this;
    }
    ~Student_info(){ std::cout << "destroy" << std::endl; }
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
bool did_all_hw(Student_info&);
#endif