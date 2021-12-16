#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pic_base.h"
using std::string;
using std::ostream;
using std::max;

void Pic_base::pad(ostream& os, wd_sz beg, wd_sz end){
    while (beg != end)
    {
        os << ' ';
        ++beg;
    }
}

Pic_base::wd_sz String_pic::width() const{
    Pic_base::wd_sz maxlen = 0;
    Pic_base::ht_sz ht = data.size();
    for(Pic_base::ht_sz i = 0; i != ht; ++i){
        maxlen = max(maxlen, data[i].size());
    }
    return maxlen;
}

void String_pic::display(std::ostream& os, ht_sz row, bool is_pad) const {
    wd_sz w = 0;
    if(row < height()){
        os << data[row];
        w = data[row].size();
    }
    if(is_pad){
        pad(os, w, width());
    }
}

void Frame_pic::display(std::ostream& os, ht_sz row, bool is_pad) const {
    if(row >= height()){
        pad(os, 0, width());
    }else{
        wd_sz col = 0;
        if(row == 0 || row == height() - 1){
            while(col != width()){
                if(col == 0 || col == width() - 1) os << corner;
                else os << top;
                ++col;
            }
        }else if(row == 1 || row == height() - 2){
            os << side << string(width() - 2, ' ') << side;
        }else if(row > 1 && row < height() - 2){
            os << side << " ";
            p->display(os, row - 2, true);
            os << " " << side;
        }
    }

}

void Vcat_pic::display(ostream& os, ht_sz row, bool is_pad) const {
    Pic_base::wd_sz w = 0;
    if(row < top->height()){
        top->display(os, row, is_pad);
        w = top->width();
    }else if(row < height()){
        bottom->display(os, row - top->height(), is_pad);
        w = bottom->width();
    }
    if(is_pad)
        pad(os, w, width());
}

void Hcat_pic::display(ostream& os, ht_sz row, bool is_pad) const {
    if(left->height() < right->height()){
        ht_sz black = (right->height() - left->height()) / 2;
        if(row < black) {
            left->display(os, left->height() + 1, is_pad || row < right->height());
            right->display(os, row, is_pad);            
        }else if(row >= left->height() + black){
            left->display(os, left->height() + 1, is_pad || row < right->height());
            right->display(os, row, is_pad);             
        }else{
            left->display(os, row - black, is_pad || row < right->height());
            right->display(os, row, is_pad);            
        }
    }
    else if(left->height() > right->height()){
        ht_sz black = (left->height() - right->height()) / 2;
        if(row < black) {
            left->display(os, row, is_pad || row < right->height());
            right->display(os, right->height() + 1, is_pad);            
        }else if(row >= right->height() + black){
            left->display(os, row, is_pad || row < right->height());
            right->display(os, right->height() + 1, is_pad);             
        }else{
            left->display(os, row, is_pad || row < right->height());
            right->display(os, row - black, is_pad);            
        }
    }
    else{
        left->display(os, row, is_pad || row < right->height());
        right->display(os, row, is_pad);
    }
}


