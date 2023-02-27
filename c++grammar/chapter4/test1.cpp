#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Student_info.h"

using namespace std;
/*
    max 내부 인자는 타입이 같아야함.
    s.name은 string 타입
    s.name.size()와 int 타입 maxlen 변수를 
    max함수에 넣었을때 제대로 동작하는가?

    s.name.size() => string::size_type 타입
    고로 maxlen 타입을 string::size_type으로 변경.
*/
int main(){
    Student_info s;
    
    string::size_type maxlen;
    s.name = "abcdefg";
    maxlen = 5;
    
    cout << max(s.name.size(), maxlen) << "\n";
    
}