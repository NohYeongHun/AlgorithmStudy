#include "frame.h"

using std::vector; using std::string;

vector<string> hcat(const vector<string>& left, const vector<string>& right){
    vector<string> ret;
    string::size_type maxlen = 0;
    maxlen = width(left);

    string temp;
    string gap(4, ' ');
    string::size_type i = 0;

    // top
    string top = string(maxlen, ' ') + gap + right[0];
    ret.push_back(top);
    while(i != left.size()){
        temp = left[i] + string(maxlen - left[i].size(), ' ') + gap + right[i + 1];
        ret.push_back(temp);
        i++;
    }
    // bottom
    string bottom = string(maxlen, ' ') + gap + right[0];
    ret.push_back(bottom);


    return ret;
}