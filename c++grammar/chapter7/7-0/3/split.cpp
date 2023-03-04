#include"split.h"
 
using std::vector;
using std::string;
using std::isspace;
using std::find_if;
 

// space return true , not space return false
bool space(char c)
{
    return isspace(c);
}

// space return false , not space return true
bool not_space(char c)
{
    return !isspace(c);
}

// scan a string of texts, split into words, return a vector that contains these words.
// (S5.6/88)
vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = str.begin();
 
    // invariant: we have processed characters original value of [i, i)
    while (i != str.end() )
    {
        // 맨 앞 빈칸 무시
        i = find_if(i, str.end(), not_space);

        // 다음 단어 끝 검색
        iter j = find_if(i, str.end(), space);

        // 단어의 끝이 아니라면?
        if(i!= j){
            // string 추가.
            ret.push_back(string(i, j));
        }
        i = j;
    }
    return ret;
}