#include <string>
#include <vector>
#include <algorithm>
#include "vec.h"
using std::string;
using std::vector;
using std::max;

string::size_type width(const Vec<string>& vec){
    string::size_type maxlen = vec[0].size();
    for(Vec<string>::size_type i = 0; i != vec.size(); ++i){
        maxlen = max(maxlen, vec[i].size());
    }
    return maxlen;
}

Vec<string> frame(const Vec<string>& vec){
    Vec<string> ret;
    string::size_type maxlen = width(vec);
    ret.push_back(string(maxlen + 4, '*'));
    for(Vec<string>::size_type i = 0; i < vec.size(); ++i){
        ret.push_back("* " + vec[i] + string(maxlen - vec[i].size(), ' ') + " *");
    }
    ret.push_back(string(maxlen + 4, '*'));
    return ret;
}

Vec<string> vcat(const Vec<string>& top, const Vec<string>& bottom){
    Vec<string> ret;
    typedef Vec<string>::size_type vec_sz;
    for(vec_sz i = 0; i < top.size(); ++i){
        ret.push_back(top[i]);
    }
    for(vec_sz i = 0; i < bottom.size(); ++i){
        ret.push_back(bottom[i]);
    }
    return ret;
}

Vec<string> hcat(const Vec<string>& left, const Vec<string>& right){
    Vec<string> ret;
    typedef Vec<string>::size_type vec_sz;
    vec_sz leftLen = left.size();
    vec_sz rigLen = right.size();
    vec_sz height = max(leftLen, rigLen);
    
    for(vec_sz i = 0; i < height; ++i){
        string line;
        if(i < leftLen){
            line += left[i] + string(1 + width(left) - left[i].size(), ' ');
        }else{
            line += string(1 + width(left), ' ');
        }
        if(i < rigLen){
            line += right[i];
        }
        ret.push_back(line);
    }
    return ret;
}
