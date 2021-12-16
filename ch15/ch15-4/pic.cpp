#include "pic.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Picture::Picture(const vector<string>& val) : p(new String_pic(val)){ }

Picture frame(const Picture& pic){
    return new Frame_pic(pic.p);
}
Picture frame(const Picture& pic, char corner, char top, char side){
    return new Frame_pic(pic.p, corner, top, side);
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