#include <iostream>
#include <bits/stdc++.h>

int main(void){
    std::cout << "What is your name?";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << std::endl << "And What is yours?";
    std::cin >> name;
    std::cout << "Hello, " << name << "; nice to meet you too!" << std::endl;

    return 0;

}