#ifndef GUARD_PERMUTED_INDEX_H
#define GUARD_PERMUTED_INDEX_H
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>   // ostringstream
#include <numeric>
 
struct Permuted_index
{
    // 시작 id
    std::vector<std::string>::size_type birth_id;
    // 구문 번호
    std::vector<std::string>::size_type line_number;
    // 현재 구문에 대한 단어 집합.
    std::vector<std::string> line_elements;
    // 현재 구문에서 시작 색인의 번호.
    std::vector<std::string>::size_type position_in_line;
    // 회전 문장의 요소들.
    std::vector<std::string> rotated_line_elements;
    // 현재 구문 전체
    std::string rotated_line;
};
 
bool compare(const Permuted_index&, const Permuted_index&);
 
std::string string_from_vec_str(const std::vector<std::string>&);
std::string string_from_vec_str_size_type(const std::vector<std::string>::size_type&);
std::string string_from_int(int);
 
void make_permuted_index_collection(const std::vector<std::string>&, std::vector<Permuted_index>&);
void sort_permuted_index_collection(std::vector<Permuted_index>&);
void print_permuted_index_collection(const std::vector<Permuted_index>&);
 
std::vector<std::string> rotate_line_elements(const std::vector<std::string>&);
std::vector<std::string> get_left_hand_side(const std::vector<Permuted_index>&);
std::vector<std::string> get_right_hand_side(const std::vector<Permuted_index>&);
std::vector<std::string> get_line_numbers(const std::vector<Permuted_index>&);
std::vector<std::string> get_word_numbers(const std::vector<Permuted_index>&);
 
#endif // GUARD_PERMUTED_INDEX_H