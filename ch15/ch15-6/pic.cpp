#include "pic.h"
#include <iostream>
#include "str.h"
#include "vec.h"
using namespace std;

Picture::Picture(const Vec<Str>& val) : p(new String_pic(val)){ }

Picture frame(const Picture& pic){
    return new Frame_pic(pic.p);
}
Picture hcat(const Picture& l, const Picture& r){
    return new Hcat_pic(l.p, r.p);
}
Picture vact(const Picture& t, const Picture& b){
    return new Vcat_pic(t.p, b.p);
}

ostream& operator<<(ostream& os, const Picture& pic){
    const Pic_base::ht_sz ht = pic.p->height();
    for(Pic_base::ht_sz i = 0; i != ht; ++i){
        pic.p->display(os, i, false);
        os << endl;
    }
    return os;
}