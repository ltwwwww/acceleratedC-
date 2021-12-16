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

vector<string> aux_gen(const GRAMMER& g){
    vector<string> ret;
    gen_sen(g, "<sentence>", ret);
    return ret;
}

void gen_sen(const GRAMMER& g, const string& str, vector<string>& ret){
    if(!is_rule(str)){
        ret.push_back(str);
    }
    else{
        GRAMMER::const_iterator it = g.find(str);
        if(it == g.end()){
            throw runtime_error("empty rule!");
        }
        const RULE_COLLECTION& c = it->second;

        const RULE& r = c[nrand(c.size())];
        for(RULE::const_iterator id = r.begin(); id != r.end(); ++id){
            gen_sen(g, *id, ret);
        }
    }
}