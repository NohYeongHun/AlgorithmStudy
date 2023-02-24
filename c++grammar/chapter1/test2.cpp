#include <iostream>
#include <bits/stdc++.h>

int main(void){

    // 이름 물어봄
    cout << "Plz enter your first name : ";
    // 이름 읽음
    std::string name;
    cin >> name;
    const std::string greeting = "Hello, " + name + "!";
    const std::string space(greeting.size(), ' ');
    const std::string second = "* " + space + " *";
    const std::string first(second.size(), '*');
    // const std::string spaces (greeting.size(),' ');
    // 

    // const std::string first (second.size(), "*");
    
    cout << "\n";
    cout << first << "\n";
    cout << second << "\n";
    cout << "* " << greeting << " *" << endl;
    cout << second << endl;
    cout << first << endl;
    
    return 0;


}