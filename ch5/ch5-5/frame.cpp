#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
using std::string;
using std::vector;
using std::max;

string::size_type width(const vector<string>& vec){
    string::size_type maxlen = vec[0].size();
    for(vector<string>::size_type i = 0; i != vec.size(); ++i){
        maxlen = max(maxlen, vec[i].size());
    }
    return maxlen;
}

vector<string> frame(const vector<string>& vec){
    vector<string> ret;
    string::size_type maxlen = width(vec);
    ret.push_back(string(maxlen + 4, '*'));
    for(vector<string>::size_type i = 0; i < vec.size(); ++i){
        ret.push_back("* " + vec[i] + string(maxlen - vec[i].size(), ' ') + " *");
    }
    ret.push_back(string(maxlen + 4, '*'));
    return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom){
    vector<string> ret;
    typedef vector<string>::size_type vec_sz;
    for(vec_sz i = 0; i < top.size(); ++i){
        ret.push_back(top[i]);
    }
    for(vec_sz i = 0; i < bottom.size(); ++i){
        ret.push_back(bottom[i]);
    }
    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right){
    vector<string> ret;
    typedef vector<string>::size_type vec_sz;
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


vector<string> center(const vector<string>& vec){
    bool flag = vec[0].size() % 2;
    for(vector<string>::size_type i = 1; i != vec.size(); ++i){
        if(vec[i].size() % 2 != flag){
            throw std::runtime_error("cannot fill");
        } 
    }
    vector<string> ret;
    string::size_type maxlen = width(vec);
    for(vector<string>::size_type i = 0; i != vec.size(); ++i){
        string line;
        line += string((maxlen - vec[i].size()) / 2, '*');
        line += vec[i];
        line += string((maxlen - vec[i].size()) / 2, '*');
        ret.push_back(line);
    }
    return ret;
}
