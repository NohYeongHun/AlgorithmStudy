#include <iostream>
#include <bits/stdc++.h>

int main(void){
    {
        
        // main 1 scope 시작
        const std::string s = "a string";
        std::cout << s << std::endl;

        {
            // main 1-1 scope 시작
            const std::string s = "another string";
            
            std::cout << s << std::endl;
            // main 1-1 scope 종료
        }
        // main 1 scope 종료
    }
    /*
        main 1 scope 내부에 main 1-1 scope가 있더라도
        main 1-1 scope 내부의 모든 로컬 변수는 main 1 scope 보기에서 숨겨진다.
        고로 main 1-1 scope에서 동작하는 행위는 문제 없이 동작한다.
        1. main 1 시작 main 1 string s 변수 메모리 할당
        2. main 1-1 시작 main 1-1 string s 변수 메모리 할당
        3. main 1-1 종료 main 1-1 string s 변수 소멸, 메모리 해제 시스템 반환
        4. main 1 종료 모든 기본 범위 로컬 변수 소멸. 메모리가 해제되고 시스템으로 반환.
    */
}