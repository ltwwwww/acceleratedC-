#pragma once
#include <stdexcept>

template <typename T>
class Ptr{
public:
    void make_unique(){
        if(*refptr != 1){
            *refptr--;
            refptr = new size_t(1);
            tp = tp? tp->clone() : 0;
        }
    }
    Ptr() : tp(0), refptr(new size_t(1)){}
    Ptr(const Ptr& rhs) : tp(rhs.tp), refptr(rhs.refptr) {
        ++*refptr;
    }
    Ptr& operator=(const Ptr&);
    ~Ptr();
    Ptr(T* t) : tp(t), refptr(new size_t(1)){}
    operator bool() const { return tp; }
    T& operator*() const;
    T* operator->() const;
private:
    T* tp;
    size_t* refptr;
};

template <typename T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs){
    ++*rhs.refptr;
    if(--*refptr == 0){
        delete tp;
        delete refptr;
    }
    tp = rhs.tp;
    refptr = rhs.refptr;
    return *this;
}

template <typename T>
Ptr<T>::~Ptr(){
    if(--*refptr == 0){
        delete tp;
        delete refptr;
    }
}

template <typename T>
T& Ptr<T>::operator*() const{
    if(tp) return *tp;
    else throw std::runtime_error("unbound printer");
}

template <typename T>
T* Ptr<T>::operator->() const{
    if(tp) return tp;
    else throw std::runtime_error("unbound printer");
}

template <typename T>
bool compare_Ptr_core(const Ptr<T>& a, const Ptr<T>& b){
    return a->name() < b->name();
}