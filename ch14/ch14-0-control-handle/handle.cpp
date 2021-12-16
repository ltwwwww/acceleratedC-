#include "handle.h"

using namespace std;

istream& Student_info::read(istream& is){
    char c;
    is >> c;
    if(c == 'U')
        hp = new Core(is);
    else
        hp = new Grad(is);
    return is;
}