#ifndef GUARD_student_info_h
#define GUARD_student_info_h
#include <iostream>
#include <string>
#include <vector>

class Core {
public:
    Core();
    Core(std::istream&);
    virtual ~Core(){ }
    virtual double grade() const;
    virtual std::istream& read(std::istream&);
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }
protected:
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;

private:
    std::string n;
};

class Grad : public Core{
public:
    Grad();
    Grad(std::istream&);
    double grade() const;
    std::istream& read(std::istream&);

private:
    double thesis;
};

bool compare(const Core&, const Core&);
bool compare_ptrs(const Core*, const Core*);
std::istream& read_hw(std::istream& is, std::vector<double>& hw);

#endif