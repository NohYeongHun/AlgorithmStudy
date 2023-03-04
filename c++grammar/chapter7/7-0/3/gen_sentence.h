#ifndef GUARD_GEN_SENTENCE_H
#define GUARD_GEN_SENTENCE_H
 
// gen_sentence.h
 
#include <string>            // std::string
#include <vector>            // std::vector
#include "read_grammar.h"    // Grammar
 
std::vector<std::string> gen_sentence(const Grammar&);
 
#endif // GUARD_GEN_SENTENCE_H