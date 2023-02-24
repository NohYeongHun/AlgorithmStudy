#include <iostream>
#include <bits/stdc++.h>

// const string exam 정의 및 값 "!"로 초기화 => const의 경우 선언과 동시에 초기화를 하지 않으면 값을 변경할 수 없음.
const std::string exam = "!";
// const string world 정의 및 값 ", world"로 초기화 => const의 경우 선언과 동시에 초기화를 하지 않으면 값을 변경할 수 없음.
const std::string world = ", world";

/*
    const string message 정의 및 값 "Hello" + ", world" + exam 초기화 실패
    => "Hello"와 ", world" 는 둘 다 문자열 리터럴로서 + 연산이 불가능함.
*/

const std::string message = "Hello" + ", world" + exam;
int main(void){
    std::cout << message;

}