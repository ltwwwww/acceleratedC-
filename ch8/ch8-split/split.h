#pragma once
#include <algorithm>
#include <cctype>
#include <string>
bool is_space(char c){
    return std::isspace(c);
}

bool is_not_space(char c){
    return !std::isspace(c);
}

template <typename In, typename Out>
void split(In b, In e, Out dst){
    while (b != e)   
    {
        b = std::find_if(b, e, is_not_space);
        if(b != e){
            In after = std::find_if(b, e, is_space);
            *dst = std::string(b, after);
            ++dst;
            b = after;
        }
    }
}