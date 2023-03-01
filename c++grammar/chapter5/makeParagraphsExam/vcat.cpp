#include "vcat.h"

using std::vector;  using std::string;
vector<string> vcat(const vector<string>& top, const vector<string>& bottom){

    // top 그림 복사
    vector<string> ret = top;


    // bottom 그림 복사
    for(vector<string>::const_iterator it = bottom.begin(); 
        it != bottom.end(); it++){
            ret.push_back(*it);
        }
    return ret;
}