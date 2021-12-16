#pragma once
#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <algorithm>
#include "split.h"

template <typename Out>
void xref(std::vector<std::string> vec, Out dst){
    std::map<std::string, std::vector<int> > ret;
    int line_num = 0;
    for(std::vector<std::string>::const_iterator it = vec.begin(); it != vec.end(); ++it){
        std::vector<std::string> words = split(*it);
        for(std::vector<std::string>::const_iterator itear = words.begin(); itear != words.end(); ++itear){
            ret[*itear].push_back(line_num);
        }
        ++line_num;
    }
    std::copy(ret.begin(), ret.end(), dst);
}
