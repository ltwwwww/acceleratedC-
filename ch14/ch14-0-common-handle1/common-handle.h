#pragma once
#include <stdexcept>

template <typename T>
class Handle{
public:
    Handle() : tp(0){}
    Handle(const Handle& rhs) : tp(0) { tp = rhs.tp?rhs.tp->clone():0;}
    Handle& operator=(const Handle&);
    ~Handle() { delete tp; }
    Handle(T* t) : tp(t){}
    operator bool(){ return tp; }
    T& operator*() const;
    T* operator->() const;
private:
    T* tp;
};


template <typename T>
Handle<T>& Handle<T>::operator=(const Handle& rhs){
    delete tp;
    if(&rhs != this){
        tp = rhs.tp? rhs.tp->clone() : 0;
    }
    return *this;
}

template <typename T>
T& Handle<T>::operator*() const{
    if(tp) return *tp;
    else throw std::runtime_error("unbound printer");
}

template <typename T>
T* Handle<T>::operator->() const{
    if(tp) return tp;
    else throw std::runtime_error("unbound printer");
}

template <typename T>
bool compare_handle_core(const Handle<T>& a, const Handle<T>& b){
    return a->name() < b->name();
}