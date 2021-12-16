#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>

typedef std::vector<std::string> RULE;
typedef std::vector<RULE> RULE_COLLECTION;
typedef std::map<std::string, RULE_COLLECTION> GRAMMER;

GRAMMER read_grammer(std::istream&);
std::vector<std::string> gen_sen(const GRAMMER&);
void gen_aux(const GRAMMER&, const std::string&, std::vector<std::string>&);