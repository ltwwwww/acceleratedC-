#ifndef GUARD_student_info_h
#define GUARD_student_info_h
#include <iostream>
#include <string>
#include <vector>
class Core {
friend class Student_info;
public:
    Core();
    Core(std::istream&);
    virtual ~Core(){ }
    virtual double grade() const;
    virtual std::istream& read(std::istream&);
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }
    virtual void regrade(double fin, double ths){
        final = fin;
    }
protected:
    
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;
public:
    virtual Core* clone() const;
private:
    std::string n;
};

class Grad : public Core{
public:
    Grad();
    Grad(std::istream&);
    double grade() const;
    std::istream& read(std::istream&);
    virtual Grad* clone() const;
    virtual void regrade(double fin, double ths = 0){
        final = fin;
        thesis = ths;
    }
private:
    double thesis;
};

bool compare(const Core&, const Core&);
bool compare_ptrs(const Core*, const Core*);
std::istream& read_hw(std::istream& is, std::vector<double>& hw);

#endif