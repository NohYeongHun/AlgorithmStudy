#ifndef GUARD_GEN_AUX_H
#define GUARD_GEN_AUX_H
#include<vector>
#include<string>
#include "read_grammar.h"

void gen_aux(const Grammar& g, const std::string& word, std::vector<std::string>& ret);
bool bracketed(const std::string& s);

#endif