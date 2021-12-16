#include "gen.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include "split.h"
#include "nrand.h"
using namespace std;

GRAMMER read_grammer(istream& in){
    GRAMMER mygra;
    string s;
    while (getline(cin, s))
    {
        vector<string> entry = split(s);
        if(!entry.empty())
            mygra[entry[0]].push_back(RULE(entry.begin() + 1, entry.end()));
    }
    return mygra;
}

bool is_rule(const string& s){
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}



