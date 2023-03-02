#include<string>
#include<iostream>

using std::equal;
using std::string;
using std::cout;
bool is_palindrome(const string& s)
{
    /*
        1. [s.begin(), s.end()) sequence 
        2. [s.rbegin() ) sequence()
        3. compare
        - comp1 s.rbegin() == s.begin()
        - comp2 s.rbegin() + 1 == s.begin + 1
        - ...
        - end comp s.rend() == s.end()
    */
    return equal(s.begin(), s.end(), s.rbegin());
}

int main(){

    string test = "abba";
    if(is_palindrome(test)){
        cout << "isPalindrome" <<"\n";
    } else {
        cout << "isNotPalindrome" <<"\n";
    }
}