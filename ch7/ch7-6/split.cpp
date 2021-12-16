#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using std::string;
using std::vector;
using std::find_if;
using std::isspace;

bool is_not_space(char x){
    return !isspace(x);
}

bool is_space(char x){
    return isspace(x);
}

vector<string> split(const string& s){
    vector<string> ret;
    typedef string::const_iterator iter;
    iter i = s.begin();
    while (i != s.end())
    {
        i = find_if(i, s.end(), is_not_space);
        iter j = find_if(i, s.end(), is_space);
        if(i != s.end())
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}