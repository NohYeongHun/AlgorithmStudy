#include "read_lines.h"
 
using std::string;
using std::vector;
using std::cin;
using std::getline;
 
// Read lines and return the line collection
vector<string> read_lines()
{
    string line;
    vector<string> ret;
    while (getline(cin, line))
        ret.push_back(line);
 
    return ret;
}