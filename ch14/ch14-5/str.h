#pragma once
#include "vec.h"
#include <algorithm>
#include <iterator>
#include <cstring>
#include <iostream>
#include "Ptr.h"
class Str{
friend std::istream& operator>>(Str&, std::istream&);
public:
    typedef Vec<char>::size_type size_type;
    Str() : data(new Vec<char>){}
    Str(size_type n, const char& ch) : data(new Vec<char>(n, ch)){}
    Str(const char* rhs) : data(new Vec<char>){
        std::copy(rhs, rhs + std::strlen(rhs), std::back_inserter(*data));
    }
    template <typename In>
    Str(In beg, In end) : data(new Vec<char>){
        std::copy(beg, end, std::back_inserter(*data));
    }
    size_type size() const { return data->size(); }
    char& operator[](size_type i) {data.make_unique(); return (*data)[i]; }
    const char& operator[](size_type i) const { return (*data)[i]; }
    Str& operator+=(const Str& s){
        data.make_unique();
        std::copy(s.data->begin(), s.data->end(), std::back_inserter(*data));
        return *this;
    }
    Str substr(size_type beg, size_type len) const;
private:
    Ptr<Vec<char>> data;
};

std::ostream& operator<<(std::ostream&, const Str&);

Str operator+(const Str&, const Str&);
