#include <iostream>
#include <bits/stdc++.h>

int main(void){
    std::cout << "What is your name?";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << std::endl << "And What is yours?";
    std::cin >> name;
    std::cout << "Hello, " << name << "; nice to meet you too!" << std::endl;
    std::cout << "Hello, " << name << "; nice to meet you too!" << std::endl;

    /*
        출력 예상
        What is your name?{name}
        Hello, {name}
        And What is yours?{name}
        Hello, {name}; nice to meet you too
        
        추가 실험
        위의 요약 섹션에서 언급한 가설을 확인하기 위해 세 가지 실험을 더 수행해 보겠습니다. 
        프로그램에 두 개의 std::cin 단계가 있음을 알고 있으므로 다음을 시도할 수 있습니다.

        실험 1: 첫 번째 std::cin 단계에서 0 단어를 입력하고 Enter 키를 누릅니다.
        실험 2: 첫 번째 std::cin 단계에서 1단어를 입력하고 Enter 키를 누릅니다.
        실험 3: 첫 번째 std::cin 단계에서 3단어를 제공하고 Enter 키를 누릅니다.

        실험 1 결과
        std::cin 단계에서 0 단어를 제공하고 Enter키를 누름
        What is your name?
        Hello, 
        And What is yours?
        Hello, ; nice to meet you too

        실험 2 결과
        첫 번째 std::cin 단계에서 1단어를 제공하고 Enter 키를 누릅니다.
        name = sss
        What is your name?sss
        Hello,sss
        And What is yours?
        Hello, sss; nice to meet you too
        
        실험 3 결과
        첫 번째 std::cin 단계에서 3단어를 제공하고 Enter 키를 누릅니다.
        name = hello tree 3
        초기 버퍼에는 3개의 단어가 포함되어 있습니다.
        첫 번째 std::cin은 버퍼에서 첫 번째 단어를 플러시합니다. 결과적으로 버퍼에는 나머지 2개 단어가 포함됩니다.
        다음 std::cin은 버퍼에서 첫 번째 단어를 플러시합니다. 결과적으로 버퍼에는 나머지 1개 단어가 포함됩니다.
        즉 첫번쨰 std::cin에 hello tree 3이 name에 할당되고
        
        처음 std::out에 hello 가 출력
        두번째 std::cin에 hello의 다음 문자인 tree가 입력됨
        두번째 std::out에 두번쨰 std::cin에서 받은 tree가 입력됨.
        
        What is your name? hello tree 3
        Hello, hello
        And What is yours?Hello, tree; Hello, tree; nice to meet you too
    */

    return 0;

}