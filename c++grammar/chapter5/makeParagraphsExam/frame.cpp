#include "frame.h"
using std::string;
using std::vector;
using std::max;

string::size_type width(const vector<string>& v){
    string::size_type maxlen = 0;

    for(vector<string>::size_type i = 0; i!= v.size(); ++i){
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;

}

vector<string> frame(const vector<string>& v){
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    // 가장 위 경계 출력
    ret.push_back(border);
    for(vector<string>::size_type i = 0; i != v.size(); i++){
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }

    // 가장 아래 경계 출력
    ret.push_back(border);

    return ret;
}