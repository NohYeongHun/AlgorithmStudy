#include<string>
#include<vector>
#include<stdexcept>
#include"read_grammar.h"
#include"nrand.h"
using std::string;
using std::vector;
using std::logic_error;

bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if (!bracketed(word)){
        ret.push_back(word);
    } else {
        // word에 해당하는 규칙의 위치를 찾습니다.
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");
        
        // 가능한 규칙의 세트 얻기.
        const Rule_collections& c = it -> second;

        // 그 중에서 하나를 무작위로 선택.
        const Rule& r = c[nrand(c.size())];

        // 선택된 규칙을 재귀적으로 확장시킴.
        for(Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}