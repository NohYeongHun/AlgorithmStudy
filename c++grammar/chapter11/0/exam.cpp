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
    // 범위 초과로 grow()함수 호출 => 배열크기 2배로 증가 =>  기존요소 복사 및 새로운 값 넣기. =>  uncreate() 함수 호출 => 
    v1.push_back(10);
    v1.push_back(15);
    v1.push_back(20);

    for(Vec<int>::iterator iter = v1.begin(); iter != v1.end(); iter++){
        cout << "현재 값 = " << *iter << '\n';
    }
    cout << '\n';
}