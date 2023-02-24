#include <iostream>
#include <bits/stdc++.h>

int main(void){
    {
        // main 1 scope 시작
        const std::string s = "a string";
        
        {
            // main 1-1 scope 시작
            std::cout << s << std::endl;
            std::cout << x << std::endl;
            // main 1-1 scope 종료
        }
        const std::string x = s + " really";

        // main 1 scope 종료
    }

    // main 1-1 scope가 실행되기전에 변수 x가 초기화되지 않았으므로 해당 문제는 오류가 있다.
    

}