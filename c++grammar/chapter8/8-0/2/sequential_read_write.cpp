#include <algorithm>
#include <vector>
#include <stdexcept>

using std::vector;

template<class For, class X>
void replace(For beg, For end, constX& x, const X& y)
{
    while (beg != end) {
        if(*beg == x)
            *beg = y;
        ++beg;
    }
}