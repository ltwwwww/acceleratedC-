#pragma once

#include "vec.h"
#include <cstring>
#include <iostream>
#include "ptr.h"

using std::istream;
using std::ostream;

class Str{
    friend std::istream& operator>>(std::istream&, Str&);

    public:
        typedef Vec<char>::size_type size_type;
        Str():data(new Vec<char>) {}
        Str(size_type n, char c): data(new Vec<char>(n, c)){}

        Str(const char* cp): data(new Vec<char>){
            std::copy(cp, cp+std::strlen(cp), std::back_inserter(*data));
        } // initialize by char string

        template<class In> Str(In b, In e): data(new Vec<char>){
            std::copy(b, e, std::back_inserter(*data));
        } //initilize by template

        char& operator[](size_type i) { 
            data.make_unique();
            return (*data)[i]; 
        }
        const char& operator[](size_type i) const { return (*data)[i]; }

        Str& operator+=(const Str& s){
            data.make_unique();
            std::copy(s.data->begin(), s.data->end(), std::back_inserter(*data));
            return *this;
        }

        size_type size() const { return data->size(); }

    private:
        Ptr<Vec<char>> data;
};

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);