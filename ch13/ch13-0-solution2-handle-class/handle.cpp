#include "handle.h"

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