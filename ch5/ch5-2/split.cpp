#include <vector>
#include <string>
#include <cctype>
using std::vector;
using std::string;
using std::isspace;

vector<string> split(const string& s){
    vector<string> ret;
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