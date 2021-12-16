#include <iostream>
#include "str.h"
#include <cctype>
using std::ostream;
using std::istream;


ostream& operator<<(ostream& os, const Str& str){
    Str::size_type i;
    for(i = 0; i != str.size(); ++i){
        os << str[i];
    }
    return os;
}

istream& operator>>(Str& str, std::istream& is){  
    str.data->clear();
    char c;
    while (is.get(c) && isspace(c));
    if(is){
        do str.data->push_back(c);
        while (is.get(c) && !isspace(c));
        if(is)  is.unget();
    }
    return is;
}
Str operator+(const Str& l, const Str& r){
    Str ret = l;
    ret + r;
    return ret;
}

Str Str::substr(size_type beg, size_type len) const{
    Str ret(data->begin() + beg, data->begin() + beg + len);
    return ret;
}
