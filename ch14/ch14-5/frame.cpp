#include "str.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
using std::vector;
using std::max;

Str::size_type width(const vector<Str>& vec){
    Str::size_type maxlen = vec[0].size();
    for(vector<Str>::size_type i = 0; i != vec.size(); ++i){
        maxlen = max(maxlen, vec[i].size());
    }
    return maxlen;
}

vector<Str> frame(const vector<Str>& vec){
    vector<Str> ret;
    Str::size_type maxlen = width(vec);
    ret.push_back(Str(maxlen + 4, '*'));
    for(vector<Str>::size_type i = 0; i < vec.size(); ++i){
        ret.push_back("* " + vec[i] + Str(maxlen - vec[i].size(), ' ') + " *");
    }
    ret.push_back(Str(maxlen + 4, '*'));
    return ret;
}

vector<Str> vcat(const vector<Str>& top, const vector<Str>& bottom){
    vector<Str> ret;
    typedef vector<Str>::size_type vec_sz;
    for(vec_sz i = 0; i < top.size(); ++i){
        ret.push_back(top[i]);
    }
    for(vec_sz i = 0; i < bottom.size(); ++i){
        ret.push_back(bottom[i]);
    }
    return ret;
}

vector<Str> hcat(const vector<Str>& left, const vector<Str>& right){
    vector<Str> ret;
    typedef vector<Str>::size_type vec_sz;
    vec_sz leftLen = left.size();
    vec_sz rigLen = right.size();
    vec_sz height = max(leftLen, rigLen);
    for(vec_sz i = 0; i < height; ++i){
        Str line;
        if(i < leftLen){
            line += left[i] + Str(1 + width(left) - left[i].size(), ' ');
        }else{
            line += Str(1 + width(left), ' ');
        }
        if(i < rigLen){
            line += right[i];
        }
        ret.push_back(line);
    }
    return ret;
}


vector<Str> center(const vector<Str>& vec){
    bool flag = vec[0].size() % 2;
    for(vector<Str>::size_type i = 1; i != vec.size(); ++i){
        if(vec[i].size() % 2 != flag){
            throw std::runtime_error("cannot fill");
        } 
    }
    vector<Str> ret;
    Str::size_type maxlen = width(vec);
    for(vector<Str>::size_type i = 0; i != vec.size(); ++i){
        Str line;
        line += Str((maxlen - vec[i].size()) / 2, '*');
        line += vec[i];
        line += Str((maxlen - vec[i].size()) / 2, '*');
        ret.push_back(line);
    }
    return ret;
}
