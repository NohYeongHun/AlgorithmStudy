#include <iostream>
#include <bits/stdc++.h>

int main(void){
    {
        // main 1-1 scope 시작
        const std::string s = "a string";
        std::cout << s << std::endl;
        // main 1-1 scope 종료
    }
    {
        // main 1-2 scope 시작
        const std::string s = "another string";
        std::cout << s << std::endl;
        // main 1-2 scope 종료
    }

    // main 1-1 scope의 s와 main 1-2 scope의 s는 다른 scope에 존재하는 지역변수이므로 문제없이 실행된다.

}   