#ifndef GUARD_READ_GRAMMAR_H
#define GUARD_READ_GRAMMAR_H
#include<vector>
#include<string>
#include<map>
#include<iostream>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collections;
typedef std::map<std::string, Rule_collections> Grammar;
Grammar read_grammar(std::istream& in);

#endif