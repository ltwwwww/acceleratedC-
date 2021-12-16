#pragma once
#include <memory>
#include <algorithm>
#include <iterator>
#include <iostream>
class Str{
friend std::istream& operator>>(std::istream&, Str&);
public:
    typedef char* iterator;
    typedef const char* const_iterator;
    typedef char value_type;
    typedef size_t size_type;

    Str(){ create(); }
    Str(size_type n, const char& val = char()){ create(n, val); }
    Str(const char*);
    
    template <typename In>
    Str(In beg, In end){ create(beg, end); }
    Str(const Str& rhs){
        create(rhs.begin(), rhs.end());
    }
    Str& operator=(const Str& rhs){
        if(this != &rhs){
            uncreate();
            create(rhs.begin(), rhs.end());
        }
        return *this;
    }
    ~Str(){ 
        // if(tempvec)
        //     delet_temp();
        uncreate(); 
    }
    iterator begin(){ return data; }
    const_iterator begin() const { return data; }
    iterator end(){ return avail; }
    const_iterator end() const { return avail; }
    size_type size() const { return avail - data; }
    char& operator[](size_type i){ return data[i]; }
    const char& operator[]( size_type i) const { return data[i]; }
    void push_back(const char& v){
        if(avail == limit) grow();
        unchecked_append(v);
    }
    iterator erease(iterator);
    void clear(){
        // if(tempvec)
        //     delet_temp();
        uncreate(); 
    }

    Str& operator+=(const Str& r){
        std::copy(r.begin(), r.end(), std::back_inserter(*this));
        return *this;
    }
    operator bool(){
        return size() > 0;
    }

    const char* c_str() ;
    const char* thedata() ;
    void copy(char*, size_type) const;
    Str substr(size_type beg, size_type len) const;
    
private:
    iterator data;
    iterator avail;
    iterator limit;

    std::allocator<char> alloc;
    char* tempvec = new char[1];

    void create();
    void create(size_type, const char&);
    void create(const_iterator, const_iterator);

    void uncreate();

    void grow();
    void unchecked_append(const char&);

    void delet_temp();
};

std::ostream& operator<<(std::ostream&, const Str&);

Str operator+(const Str&, const Str&);
Str operator+(const Str&, const char*);
Str operator+(const char*, const Str&);

bool operator<(const Str&, const Str&);
bool operator>(const Str&, const Str&);
bool operator<=(const Str&, const Str&);
bool operator>=(const Str&, const Str&);
bool operator==(const Str&, const Str&);
bool operator!=(const Str&, const Str&);

std::istream& getline(std::istream&, Str&);