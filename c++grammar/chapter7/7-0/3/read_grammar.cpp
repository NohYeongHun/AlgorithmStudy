#include "split.h"
#include "read_grammar.h"

using std::istream;
using std::string;
using std::vector;

Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    // 입력을 읽습니다.
    while(getline(in, line)) {
        // 입력을 단어별로 나눕니다.
        vector<string> entry = split(line);

        if(!entry.empty()) {
            // 카테고리를 사용하여 연관 규칙 저장.
            ret[entry[0]].push_back(
                Rule(entry.begin() + 1, entry.end()));
        }
    }
    return ret;
}