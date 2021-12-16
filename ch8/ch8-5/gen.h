#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdexcept>
#include "nrand.h"

typedef std::vector<std::string> RULE;
typedef std::vector<RULE> RULE_COLLECTION;
typedef std::map<std::string, RULE_COLLECTION> GRAMMER;

GRAMMER read_grammer(std::istream&);
bool is_rule(const std::string&);
template <typename Out>
void aux_gen(const GRAMMER&, Out);
template <typename Out>
void gen_sen(const GRAMMER&, const std::string&, Out);


template <typename Out>
void aux_gen(const GRAMMER& g, Out dst){
    gen_sen(g, "<sentence>", dst);
}

template <typename Out>
void gen_sen(const GRAMMER& g, const std::string& str, Out out){
    if(!is_rule(str)){
        *out = str;
        out++;
    }
    else{
        GRAMMER::const_iterator it = g.find(str);
        if(it == g.end()){
            throw std::runtime_error("empty rule!");
        }
        const RULE_COLLECTION& c = it->second;

        const RULE& r = c[nrand(c.size())];
        for(RULE::const_iterator id = r.begin(); id != r.end(); ++id){
            gen_sen(g, *id, out);
        }
    }
}