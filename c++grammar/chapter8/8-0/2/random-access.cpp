#include <algorithm>
#include <vector>
#include <stdexcept>

using std::vector;

template<class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end) {
        // 범위 중간 위치 찾기
        Ran mid = begin + (end - begin) / 2;

        // 어느 범위에 x가 포함되는지 확인하여, 해당 범위만 검색.
        if (x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        // 여기 까지 왔다면, *mid == xL
        else return true;
    }
    return false;
}