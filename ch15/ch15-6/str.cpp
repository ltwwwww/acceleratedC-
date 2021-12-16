#include "str.h"
#include <iostream>

using std::istream;
using std::ostream;

ostream& operator<<(ostream& os, const Str& s){
    for(Str::size_type i = 0; i != s.size(); i++){
        os << s[i];
    }
    return os;
}

istream& operator>>(istream& is, Str& s){
    s.data->clear();
    char c;
    while(is.get(c) && isspace(c)){
        ;
    }
    if(is){
        do s.data->push_back(c);
        while(is.get(c) && !isspace(c));

        if(is) is.unget();
    }
    return is;
}

Str operator+(const Str& s, const Str& t){
    Str ret = s;
    ret += t;
    return ret;
}