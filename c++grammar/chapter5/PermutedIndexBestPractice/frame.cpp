#include <string>      // std::string
#include <vector>      // std::vector
#include <algorithm>   // std::max
 
using std::string;
using std::vector;
using std::max;
 
string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for(vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}
 
vector<string> frame(const vector<string>& v, const string& align, char c)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string symbol(1, c);
    string border(maxlen + 4, c);
 
    // write the top border
    ret.push_back(border);
 
    // write each interior row, bordered by an asterisk and a space
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        if (align == "left")
            ret.push_back(symbol + " " + v[i] + string(maxlen - v[i].size(), ' ') + " " + symbol);
        else if (align == "right")
            ret.push_back(symbol + " " + string(maxlen - v[i].size(), ' ') + v[i]  + " " + symbol);
 
    // write the bottom border
    ret.push_back(border);
 
    return ret;
}