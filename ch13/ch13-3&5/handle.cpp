#include "handle.h"
#include <string>
using namespace std;

Student_info::Student_info(const Student_info& rhs) : cp(0){
    if(rhs.cp) cp = rhs.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& rhs){
    if(&rhs != this){
        delete cp;
        if(rhs.cp)
            cp = rhs.cp->clone();
        else
            cp = 0;
    }
    return *this;
}

istream& Student_info::read(istream& is){
    delete cp;
    char c;
    is >> c;
    if(c == 'U')
        cp = new Core(is);
    else
        cp = new Grad(is);
    return is;
}

string Student_info::grade_str() const{
    static const int num[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };
    
    static const char* const str[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    const size_t len = sizeof(num) / sizeof(*num);

    for(size_t i = 0; i < len; ++i){
        if(grade() >= num[i]) return str[i];
    }
    return "\?\?\?";
}