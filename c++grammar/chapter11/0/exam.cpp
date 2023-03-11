#include<iostream>
using std::ostream;
using std::cout;
using std::endl;

#include "vec.h"

using std::cout;
using std::endl;
int main()
{   
    // 초기화
    Vec<int> v1(2, 0);
    v1.push_back(10);
    v1.push_back(15);
    v1.push_back(20);

    for(Vec<int>::iterator iter = v1.begin(); iter != v1.end(); iter++){
        cout << "현재 값 = " << *iter << '\n';
    }
    cout << '\n';
}