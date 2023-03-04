#ifndef GUARD_SPLIT_H
#define GUARD_SPLIT_H
 
#include <algorithm>
#include <vector>
#include <string> 
#include <cctype> 

// space return true , not space return false
bool space(char c)
{
    return std::isspace(c);
}

// space return false , not space return true
bool not_space(char c)
{
    return !std::isspace(c);
}


template<class Out> // 변경됨
void split(const std::string& str, Out os) { // 변경됨

    typedef std::string::const_iterator iter;

    if(str.empty()) return;

    iter i = str.begin();

    while( i != str.end()) {
        // 처음 빈칸들은 무시
        i = std::find_if(i, str.end(), not_space);

        // 다음 단어의 끝을 찾음
        iter j = std::find_if(i, str.end(), space);

        if(i!= str.end()){
            *os++ = std::string(i, j); // 변경됨
        } 
        i = j;
    } 
}

#endif // GUARD_SPLIT_H