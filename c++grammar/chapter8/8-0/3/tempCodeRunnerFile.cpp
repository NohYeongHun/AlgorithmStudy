#include <algorithm>
#include <iostream>
#include "split.h"


using std::vector;
using std::string;
using std::ostream_iterator;
using std::cout;
using std::cin;

int main()
{
    string s;
    while (getline(cin, s)){
        split(s, ostream_iterator<string>(cout, "\n"));
    }
    return 0;
}