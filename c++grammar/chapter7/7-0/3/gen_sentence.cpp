#include<vector>
#include<string>
#include"read_grammar.h"
#include"gen_aux.h"


using std::vector;
using std::string;

vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}