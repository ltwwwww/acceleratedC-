#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Ptr.h"
class Picture;
class Pic_base{
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend class String_pic;
    friend class Frame_pic;
    friend class Vcat_pic;
    friend class Hcat_pic;
    friend class Picture;
    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type wd_sz;
    virtual ht_sz height() const = 0;
    virtual wd_sz width() const = 0;
    virtual void display(std::ostream&, ht_sz, bool) const = 0;
    virtual void reframe(char,char,char) = 0;
protected:
    static void pad(std::ostream&, wd_sz, wd_sz);
};

class String_pic : public Pic_base {
    friend class Picture;
    String_pic(const std::vector<std::string>& v) : data(v){}
    std::vector<std::string> data;
    virtual ht_sz height() const { return data.size(); }
    virtual wd_sz width() const;
    virtual void display(std::ostream&, ht_sz, bool) const;
    virtual void reframe(char corner, char top, char side){}
};

class Frame_pic : public Pic_base {
    friend Picture frame(const Picture&);
    friend Picture frame(const Picture&,char,char,char);
    Frame_pic(const Ptr<Pic_base>& rhs, char cor = '+', char to = '-', char si = '|') 
        : p(rhs), corner(cor), top(to), side(si) {}
    Ptr<Pic_base> p;
    char corner;
    char top;
    char side;
    virtual ht_sz height() const { return p->height() + 4; }
    virtual wd_sz width() const { return p->width() + 4; }
    virtual void display(std::ostream&, ht_sz, bool) const;
    virtual void reframe(char corner, char top, char side){
        this->corner = corner;
        this->top = top;
        this->side = side;

        p->reframe(corner, top, side);
    }
};

class Vcat_pic : public Pic_base {
    friend Picture vact(const Picture&, const Picture&);
    Vcat_pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b) : top(t), bottom(b){ }
    Ptr<Pic_base> top, bottom;
    virtual ht_sz height() const { return top->height() + bottom->height(); }
    virtual wd_sz width() const { return std::max( top->width(), bottom -> width());}
    virtual void display(std::ostream&, ht_sz, bool) const;
    virtual void reframe(char corner, char top, char side){
        this->top->reframe(corner, top, side);
        bottom->reframe(corner, top, side);
    }
};

class Hcat_pic : public Pic_base {
    friend Picture hcat(const Picture&, const Picture&);
    Hcat_pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r) : left(l), right(r) {};
    Ptr<Pic_base> left, right;
    virtual ht_sz height() const { return std::max(left->height(), right->height()); }
    virtual wd_sz width() const { return left->width() + right->width(); }
    virtual void display(std::ostream&, ht_sz, bool) const;
    virtual void reframe(char corner, char top, char side){
        left->reframe(corner, top, side);
        right->reframe(corner, top, side);
    }
};