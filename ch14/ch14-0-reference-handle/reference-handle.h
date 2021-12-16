#pragma once
#include <stdexcept>

template <typename T>
class Ref_handle{
public:
    Ref_handle() : tp(0), refptr(new size_t(1)){}
    Ref_handle(const Ref_handle& rhs) : tp(rhs.tp), refptr(rhs.refptr) {
        ++*refptr;
    }
    Ref_handle& operator=(const Ref_handle&);
    ~Ref_handle();
    Ref_handle(T* t) : tp(t), refptr(new size_t(1)){}
    operator bool() const { return tp; }
    T& operator*() const;
    T* operator->() const;
private:
    T* tp;
    size_t* refptr;
};

template <typename T>
Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs){
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
Ref_handle<T>::~Ref_handle(){
    if(--*refptr == 0){
        delete tp;
        delete refptr;
    }
}

template <typename T>
T& Ref_handle<T>::operator*() const{
    if(tp) return *tp;
    else throw std::runtime_error("unbound printer");
}

template <typename T>
T* Ref_handle<T>::operator->() const{
    if(tp) return tp;
    else throw std::runtime_error("unbound printer");
}

template <typename T>
bool compare_Ref_handle_core(const Ref_handle<T>& a, const Ref_handle<T>& b){
    return a->name() < b->name();
}