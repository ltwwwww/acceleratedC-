#include <vector>
#include <string>
#include <cctype>
#include "string_list.h"
using std::vector;
using std::string;
using std::isspace;

String_list split(const string& s){
    String_list ret;
    typedef string::size_type str_sz;
    str_sz i = 0;
    while(i != s.size()){
        while( isspace(s[i])){
            ++i;
        }
        if(i != s.size()){
            str_sz j = i;
            while (!isspace(s[j]) && j != s.size())
            {
                ++j;
            }
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}