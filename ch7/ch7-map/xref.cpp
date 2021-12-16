#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "split.h"

using std::map;
using std::vector;
using std::string;

map<string, vector<int> >  xref(vector<string> vec){
    map<string, vector<int> > ret;
    int line_num = 0;
    for(vector<string>::const_iterator it = vec.begin(); it != vec.end(); ++it){
        vector<string> words = split(*it);
        for(vector<string>::const_iterator itear = words.begin(); itear != words.end(); ++itear){
            ret[*itear].push_back(line_num);
        }
        ++line_num;
    }
    return ret;
}
