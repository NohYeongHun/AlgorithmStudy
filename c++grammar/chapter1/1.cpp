#include <iostream>
#include <bits/stdc++.h>

// 상수 string hello 정의 및 "Hello" 값 초기화
const std::string hello = "Hello";
/*
    상수 message 정의 및 hello + ", world" + "!" 값 초기화 => 
    연산 순서 
    1. hello + ", world" => "hello, world"
    2. "hello, world" + "!" => "hello, world!"
 */
const std::string message = hello + ", world" + "!";
int main(void){
    std::cout << message;

}