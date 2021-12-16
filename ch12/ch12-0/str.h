#pragma once
#include "vec.h"
#include <algorithm>
#include <iterator>
#include <cstring>
#include <iostream>
class Str{
friend std::istream& operator>>(Str&, std::istream&);
public:
    typedef Vec<char>::size_type size_type;
    Str(){}
    Str(size_type n, const char& ch) : data(n, ch){}
    Str(const char* rhs){
        std::copy(rhs, rhs + std::strlen(rhs), std::back_inserter(data));
    }
    template <typename In>
    Str(In beg, In end){
        std::copy(beg, end, std::back_inserter(data));
    }
    size_type size() const { return data.size(); }
    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }
    Str& operator+=(const Str& s){
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
        return *this;
    }
private:
    Vec<char> data;
};

std::ostream& operator<<(std::ostream&, const Str&);

Str operator+(const Str&, const Str&);