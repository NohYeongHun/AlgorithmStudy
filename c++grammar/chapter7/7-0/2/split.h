#ifndef GUARD_SPLIT_H
#define GUARD_SPLIT_H
 
#include <string>    // string
#include <vector>    // vector
#include <cctype>    // isspace
 
bool space(char c);
bool not_space(char c);
std::vector<std::string> split(const std::string&);
 
#endif // GUARD_SPLIT_H