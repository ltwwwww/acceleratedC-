#include <memory>
#include "str.h"
#include <algorithm> 
#include <cstring>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

Str::Str(const char* pt){
    data = alloc.allocate(strlen(pt));
    limit = avail = uninitialized_copy(pt, pt + strlen(pt), data);
}

Str::Str(const string& rhs){
    create(rhs.begin(), rhs.end());
}

void Str::create(){
    data = limit = avail = 0;
}

void Str::create(size_type n, const char& val){
    data = alloc.allocate(n);
    avail = limit = data + n;
    uninitialized_fill(data, limit, val);
}

void Str::create(const_iterator beg, const_iterator end){
    data = alloc.allocate(end - beg);
    limit = avail = uninitialized_copy(beg, end, data);
}

void Str::uncreate(){
    if(data){
        iterator it = avail;
        while (it != data)
        {
            alloc.destroy(--it);
        }
        alloc.deallocate(data, limit - data);
    }
    data = limit = avail = 0;
}

void Str::grow(){
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);
    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

void Str::unchecked_append(const char& c){
    alloc.construct(avail++, c);
}

Str::iterator Str::erease(iterator it){
    if(it >= data && it < avail){
            while (it != avail - 1)
            {
                *it = *(it + 1);
                ++it;
            }
            alloc.destroy(avail - 1);
    }
    avail = avail - 1;
    if(size() < (limit - data) / 4){
        size_type new_size = (limit - data) / 2;
        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(data, avail, new_data);
        iterator new_limit = new_data + new_size;

        uncreate();
        data = new_data;
        limit = new_limit;
        avail = new_avail;
    }
    return it;
}

istream& operator>>(istream& is, Str& str){
    str.clear();
    // copy(istream_iterator<char>(is), istream_iterator<char>(), back_inserter(str));
    if(is){
        char c;
        while (is.get(c) && isspace(c));
        if(is){
            do str.push_back(c);
            while (is.get(c) && !isspace(c));
            if(is) is.unget();
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const Str& str){
    copy(str.begin(), str.end(), ostream_iterator<char>(os));
    // for(Str::const_iterator i = str.begin(); i != str.end(); ++i){
    //     os << *i;
    // }
    return os;
}

Str operator+(const Str& l, const Str& r){
    Str ret = l;
    ret += r;
    return ret;
}

Str operator+(const Str& l, const char* r){
    Str ret = l;
    ret += Str(r, r + strlen(r));
    return ret;
}

Str operator+(const char* l, const Str& r){
    Str ret(l, l + strlen(l));
    ret += r;
    return ret;
}

const char* Str::c_str(){
    tempvec = new char[size() + 1];
    std::copy(data, data + size(), tempvec);
    tempvec[size()] = '\0';
    return tempvec;
}

const char* Str::thedata(){
    tempvec = new char[size()];
    std::copy(data, data + size(), tempvec);
    return tempvec;
}

void Str::copy(char* dst, size_type n) const{
    std::copy(data, data + n, dst);
}

void Str::delet_temp(){
    delete[] tempvec;
}

bool operator<(const Str& l, const Str& r){
    return (strcmp(l.begin(), r.begin()) < 0);
}

bool operator>(const Str& l, const Str& r){
    return (strcmp(l.begin(), r.begin()) > 0);
}

bool operator<=(const Str& l, const Str& r){
    return (strcmp(l.begin(), r.begin()) <= 0);
}

bool operator>=(const Str& l, const Str& r){
    return (strcmp(l.begin(), r.begin()) >= 0);
}

bool operator==(const Str& l, const Str& r){
    return (strcmp(l.begin(), r.begin()) == 0);
}

bool operator!=(const Str& l, const Str& r){
    return (strcmp(l.begin(), r.begin()) != 0);
}

std::istream& getline(std::istream& is, Str& str){
    if(is){
        char c;
        while (is.get(c) && isspace(c));
        if(is){
            do str.push_back(c);
            while(is.get(c) && c != '\n');
            if(is) is.unget();
        }
    }
    return is;
}

