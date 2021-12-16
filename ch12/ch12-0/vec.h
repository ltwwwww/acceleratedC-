#pragma once
#include <memory>
#include <algorithm>
template <typename T>
class Vec
{
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef T value_type;
    typedef size_t size_type;
    Vec() { create(); }
    explicit Vec(size_type n, const T& val = T()){ create(n, val); }
    Vec(const Vec& rhs){
        create(rhs.begin(), rhs.end());
    }
    Vec& operator=(const Vec&);
    ~Vec() { uncreate(); }
    size_type size() const { return avail - data; }
    iterator begin(){ return data; }
    const_iterator begin() const { return data; }
    iterator end() { return avail; }
    const_iterator end() const { return avail; }
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }
    void push_back(const T& t){
        if(avail == limit) grow();
        unchecked_append(t);
    }

    iterator erease(iterator it){
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

    void clear(){
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


private:
    iterator data;
    iterator avail;
    iterator limit;
    std::allocator<T> alloc;
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    void uncreate();

    void grow();
    void unchecked_append(const T&);


};

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec& rhs){
    if(this != &rhs){
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <typename T>
void Vec<T>::create(){
    data = avail = limit = 0;
}

template <typename T>
void Vec<T>::create(size_type n, const T& val){
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <typename T>
void Vec<T>::create(const_iterator beg, const_iterator end){
    data = alloc.allocate(end - beg);
    limit = avail = std::uninitialized_copy(beg, end, data);
}

template <typename T>
void Vec<T>::uncreate(){
    if(data){
        iterator it = avail;
        while(it != data){
            alloc.destroy(--it);
        }
        alloc.deallocate(data, limit - data);
    }
    data = avail = limit = 0;
}

template <typename T>
void Vec<T>::grow(){
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);
    iterator new_limit = new_data + new_size;

    uncreate();
    data = new_data;
    limit = new_limit;
    avail = new_avail;
}

template <typename T>
void Vec<T>::unchecked_append(const T& t){
    alloc.construct(avail++, t);
}