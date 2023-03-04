#include <algorithm>
#include <vector>
#include <stdexcept>

using std::vector;

template<class Bi> void reverse(Bi begin, Bi end)
{
    while(begin != end) {
        --end;

        if (begin != end)
            swap(*begin++, *end);
    }
}