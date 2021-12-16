#pragma once
#include <memory>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
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
    Str(const std::string&);
    
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
    ~Str(){ uncreate(); }
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
        delet_temp();
        uncreate(); 
    }
    template<typename In> void assign(In, In);
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
    template <typename In> void insert(iterator, In, In);
    
private:
    iterator data;
    iterator avail;
    iterator limit;

    std::allocator<char> alloc;
    char* tempvec;

    void create();
    void create(size_type, const char&);
    void create(const_iterator, const_iterator);
    template<typename In> void create(In beg, In end){
        data = alloc.allocate(end - beg);
        limit = avail = std::uninitialized_copy(beg, end, data);
    }

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

template <typename In> 
void Str::insert(iterator point, In beg, In end){
    size_type new_size = size() + (end - beg);
    iterator new_data = alloc.allocate(new_size);
    std::uninitialized_copy(data, point, new_data);
    std::uninitialized_copy(beg, end, new_data + (point - data));
    iterator new_avail = std::uninitialized_copy(point, avail, new_data + (point - data) + (end - beg));
    
    uncreate();

    data = new_data;
    limit = avail = new_avail;
}

template <typename In>
void Str::assign(In beg, In end){
    uncreate();
    create(beg, end);
}

